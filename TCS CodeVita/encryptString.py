s = "Attack cnsid sdcsivn sdjkjkcsdj"

sub = ''

l = []
for c in s:
    if(len(sub) == 6):
        l.append(sub)
        sub = ''
    if(c == ' '):
        sub += '*'
    else:
        sub += c


if(len(sub) != 0):
    for i in range(len(sub), 6):
        sub += '.'
    l.append(sub)


print(l)
