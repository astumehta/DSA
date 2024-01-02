import re

text = """Mr. Anderson 
Ms. Thareja 
Mrs. Morris 
Mr. Roy 
Ms. Gandhi 
Mrs. Modi 
https://www.google.com 
http://www.udemy.com 
www.udacity.com 
https://www.stackoverflow.com 
http://www.djsce.ac.in 
https://plus.google.com 
rishit.grover@gmail.com 
kapeesh.grover@yahoo.co.in 
abhishek.shah@gmail.com 
shahp98@gmail.com 
demo_user@gmail.com 
rolflmoa@yahoo.co.in 
27777647 
233*333*88 
455-78-888 
022-240-93836 
02642*221*381"""

websites = re.findall(r'(?:https?://)?(?:www\.)?([^\s@]+\.[a-zA-Z]{2,}(?!\S))', text) 
print("Website names:", websites)
