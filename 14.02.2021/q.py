def to_rim(n):
    result=''
    for ar, rom in zip((1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1),
                        'M CM D CD C XC L XL X IX V IV I'.split()):
        result += n // ar * rom
        n %= ar
    return result

def before(str):
    num=int(str[:-2])
    num=-1*num+754
    return num

def after(str):
    num=int(str[:-2])
    num+=753
    return num

def convert(str):
    data=str.split('-')
    f=data[0]
    s=data[1]
    if f.find('BC')>-1:
        f=before(f)
    else:
        f=after(f)
    if s.find('BC')>-1:
        s=before(s)
    else:
        s=after(s)
    max_len=0
    for i in range(f,s+1):
        l=len(to_rim(i))
        if l>max_len:
            max_len=l
    return max_len

str=input()
print(convert(str))