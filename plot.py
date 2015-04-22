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

data = pd.read_csv('data/{}/data.tsv'.format(sample), sep='\t')

data[Right] = data.apply(lambda row: row[Guess] == row[Ans], axis=1)
data.sort([Right, Ans], ascending=[0, 0], inplace=True)

color = np.matrix([
    ['blue', 'lightgray'],
    ['red', 'lightpink'],
])
data[Color] = data.apply(lambda row: color[row[Guess], row[Right]], axis=1)

plot.scatter(data[X], data[Y], c=data[Color], edgecolor='none')

x     = np.arange(np.min(data[X]), np.max(data[X]))
hi    = 0.35
lo    = 0.228
peak  = 580
boost = 0.03
y     = lo + (hi - lo) / (1 + np.exp(-boost * (x - peak)))
plot.plot(x, y)

def annotateRow(row):
    label = 'data/{0}/sources/{1} data/{0}/sources/{2}'.format(sample, row[I], row[J])
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
