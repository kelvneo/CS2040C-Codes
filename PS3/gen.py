#!/usr/bin/env python3
import itertools, string, random

def excel_cols():
    n = 1
    while True:
        yield from (''.join(group) for group in itertools.product(string.ascii_uppercase, repeat=n))
        n += 1

names = list(itertools.islice(excel_cols(), 200000))
with open('PS3/largeinput.txt', 'w') as f:
    f.write('1000000\n')
    for n in names:
        f.write('0 ' + n + ' 1\n')
    
    for i in range(600000):
        cmd = random.choice([1, 1, 1, 1, 1, 1, 1, 3, 3, 2])
        nid = random.randrange(len(names) // 10)
        name = names[nid]
        if cmd == 1:
            f.write('1 ' + name + ' ' + str(random.randrange(0, 2)) + '\n')
        elif cmd == 2:
            f.write('2 ' + name + '\n')
            del names[nid]
        else:
            f.write('3\n')

    for i in range(200000 - len(names)):
        f.write('1 ' + names[random.randrange(len(names))] + ' ' + str(random.randrange(0, 2)) + '\n')
    
    while(names):
        f.write('2 ' + names.pop(0) + '\n')
