import argparse

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
    for group in groups:
        for other in groups:
            if other == group:
                break
            if set(group) & set(other):
                return None
    return pairs

misses = {}
was    = {}

def score_sample(sample):
    global misses
    with open('data/{}/ans.txt'.format(sample)) as f:
        correct = read_answer(f)
    with open('data/{}/output.txt'.format(sample)) as f:
        given = read_answer(f)
    if given is None:
        score = 0
        print(' PE', end=' ')
    elif given.issubset(correct):
        if correct:
            score = int(round(len(given) * 100. / len(correct)))
        else:
            score = 100
        print('{:3}'.format(score), end=' ')
        for i in correct - given:
            misses.setdefault(sample, []).append(i)
    else:
        score = 0
        print(' WA', end=' ')
        for i in given - correct:
            was.setdefault(sample, []).append(i)
    return score

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--no-misses', action='store_true')
    parser.add_argument('--no-was', action='store_true')
    parser.add_argument('samples', nargs='*')
    args = parser.parse_args()
    samples = args.samples
    print_misses = not args.no_misses
    print_was = not args.no_was

    score = 0
    for sample in samples:
        score += score_sample(sample)
    print('| {} / {}'.format(score, len(samples) * 100))
    if print_was and was:
        for sample in sorted(was.keys()):
            print('{} WAs:'.format(sample))
            for a, b in was[sample]:
                print(' data/{}/sources/{} data/{}/sources/{}'.format(sample, a, sample, b))
    if print_misses and misses:
        for sample in sorted(misses.keys()):
            print('{} misses:'.format(sample))
            for a, b in misses[sample]:
                print(' data/{}/sources/{} data/{}/sources/{}'.format(sample, a, sample, b))

if __name__ == '__main__':
    main()
