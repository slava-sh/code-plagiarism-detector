import numpy as np
import pandas as pd
import matplotlib.pyplot as plot
import xml.etree.ElementTree as ET
from io import StringIO
import json
import sys

plot.rcParams['figure.figsize'] = 8, 8
plot.rcParams['svg.fonttype'] = 'none'
ET.register_namespace('','http://www.w3.org/2000/svg')

Ans   = 'Ans'
Color = 'Color'
Guess = 'Guess'
I     = 'I'
J     = 'J'
Right = 'Right'
X     = 'Size'
Y     = 'DistRatio'

sample = sys.argv[1]
cumulative_samples = ['all', 'final']

data = pd.read_csv('data/{}/data.tsv'.format(sample), sep='\t')

data[Right] = data.apply(lambda row: row[Guess] == row[Ans], axis=1)
data.sort([Right, Ans], ascending=[0, 0], inplace=True)

color = np.matrix([
    ['steelblue', 'red'],
    ['lightskyblue', 'lightpink'],
])
data[Color] = data.apply(lambda row: color[row[Right], row[Ans]], axis=1)

plot.scatter(data[X], data[Y], c=data[Color], edgecolor='none')

xmin, xmax = plot.xlim()
ymin, ymax = plot.ylim()
if xmin < 0:
    xmin = 0
if sample in cumulative_samples:
    xmax = min(xmax, 1500)
if ymin < 0:
    ymin = 0
if ymax > 2:
    ymax = 2

if sample in cumulative_samples:
    title = '{} Tests'.format(sample.capitalize())
else:
    title = 'Test {}'.format(sample)
plot.title(title)
plot.xlabel('Fingerprint Size Mean')
plot.ylabel('Distance Ratio')

def sigmoid(lo, hi, peak, boost):
    return lambda x: lo + (hi - lo) / (1 + np.exp(-boost * (x - peak)))

small_threshold = 350

x     = np.arange(max(small_threshold, xmin), xmax + 1)
hi    = 0.35
lo    = 0.228
peak  = 580
boost = 0.03
line  = plot.plot(x, sigmoid(lo, hi, peak, boost)(x))[0]
line.set_color('g')

x     = np.arange(xmin, min(small_threshold, xmax + 1))
hi    = lo
lo    = -hi
peak  = 0
boost = 0.0228
line  = plot.plot(x, sigmoid(lo, hi, peak, boost)(x))[0]
line.set_color('g')

plot.xlim(xmin, xmax)
plot.ylim(ymin, ymax)

def annotateRow(row):
    label = 'data/*/sources/{} data/*/sources/{}'.format(row[I], row[J])
    xy = (row[X], row[Y])
    annotation = plot.annotate(label, xy=xy)
    annotation.set_gid('point-{}'.format(row.name))

annotatedData = data[~data[Right] | data[Ans]]
annotatedData.apply(annotateRow, axis=1)

script = '''
<script type="text/ecmascript">
<![CDATA[
function onLoad() {
    labels = document.querySelectorAll('g[id^="point-"]');
    for (var i = 0, label; label = labels[i]; ++i) {
        var text = label.querySelector('text');
        var x = text.attributes.x.value;
        var y = text.attributes.y.value;
        var point = document.querySelector('use[x="' + x + '"][y="' + y + '"]');
        var toggleLabel = (function(label) {
            label.style.display = label.style.display == '' ? 'none' : '';
        }).bind(null, label);
        point.addEventListener('click', toggleLabel);
        label.style.display = 'none';
    }
}
]]>
</script>
'''

f = StringIO()
plot.savefig(f, format='svg')
tree, xmlid = ET.XMLID(f.getvalue())
tree.insert(0, ET.XML(script))
tree.set('onload', 'onLoad()')
ET.ElementTree(tree).write('data/{}/data.svg'.format(sample))
