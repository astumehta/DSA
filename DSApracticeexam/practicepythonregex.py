import re

with open('TEXT.txt','r',encoding='utf-8') as f:
    contents=f.read()

pattern=re.compile(r'https?://(www\.)?(\w+\.\w+){1,}')
matches=pattern.finditer(contents)
for match in matches:
    print(match.group(2,))

pattern=re.compile(r'[a-zA-Z0-9._]+\@[a-z.]+')
matches=pattern.finditer(contents)
for match in matches:
    print(match)

pattern=re.compile(r'((\d{3}|\d{5})[*-](\d{3}|\d{2})[*-][0-9]|\d{8})+')
matches=pattern.finditer(contents)
for match in matches:
    print(match)



