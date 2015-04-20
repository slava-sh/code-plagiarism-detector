import sys
import os

def main():
    sample = sys.argv[1]
    with open('{}/input.txt'.format(sample)) as f:
        n = int(f.readline())
        files = [f.readline().strip() for i in range(n)]

    groups = {}
    for filename in files:
        team, task, submit = filename.split('-')
        extension = submit.split('.')[1]
        groups.setdefault((team, task, extension), []).append(filename)

    ans = []
    for group in groups.values():
        if len(group) > 1:
            ans.append(' '.join(group))
    ans = [str(len(ans))] + ans + ['']
    ans = '\n'.join(ans)
    print(ans, end='')

    ans_filename = '{}/ans.txt'.format(sample)
    if not os.path.isfile(filename):
        with open(ans_filename, 'w') as f:
            f.write(ans)

if __name__ == '__main__':
    main()
