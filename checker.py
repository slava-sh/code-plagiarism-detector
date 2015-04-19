import sys

def read_answer(f):
    groups = list(map(lambda line: line.split(), f.readlines()[1:]))
    pairs = set()
    for group in groups:
        group.sort()
        for i in group:
            for j in group:
                if j == i:
                    break
                pairs.add((j, i))
    return pairs

def score_sample(sample):
    with open('samples/{}.a'.format(sample)) as f:
        correct = read_answer(f)
    with open('{}/output.txt'.format(sample)) as f:
        given = read_answer(f)
    if given.issubset(correct):
        score = int(round(len(given) * 100. / len(correct)))
        print('{} AC {}'.format(sample, score))
    else:
        score = 0
        print('{} WA'.format(sample))
    return score

def main():
    samples = sys.argv[1:]
    if not samples:
        samples = '01 02 03 04 05 06 07 08 09 10'.split()
    score = 0
    for sample in samples:
        score += score_sample(sample)
    print('Total: {}'.format(score))

if __name__ == '__main__':
    main()