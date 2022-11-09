
last update : 20221109_2043(UTC+8)   
  
prev update : 20221109_2043(UTC+8)  
  
---------------------------------------------  
  
Markdown Cheat Sheet - quick reference to Markdown syntax  
  https://www.markdownguide.org/cheat-sheet/  
  https://www.markdownguide.org/extended-syntax/  
  
MarkDown - create auto numbered list  
  
[diy_count]: 1
1. echo.1 [diy_count]
[diy_count]: diy_count+1
1. echo.2 [diy_count]
[diy_count]: diy_count+2
1. echo.3 [diy_count]
  
Markdown - Format - Math support  
  https://github.blog/2022-05-19-math-support-in-markdown/  
  https://csrgxtu.github.io/2015/03/20/Writing-Mathematic-Fomulars-in-Markdown/  
  
inline   $\sum_{n=1}^{10} n^2$  
  
$$\sum_{n=1}^{10} n^2$$  
  
  **The Cauchy-Schwarz Inequality**  
  $$\left( \sum_{k=1}^n a_k b_k \right)^2 \leq \left( \sum_{k=1}^n a_k^2 \right) \left( \sum_{k=1}^n b_k^2 \right)$$  
  
MarkDown - Format - Syntax Highlight  
  
```js
var a = 3;
while (not (a > 0)) {
    alert("JavaScript code <b>goes</b> here.");
}
```
  
---------------------------------------------  
---  
<!--#
NOUN=mother
ATTRIBUTION=Mark Wahlberg
$-->

"Say hi to your {{ NOUN }} for me," {{ ATTRIBUTION }} {{ nameOfVariableToCapture }}
  
{% capture nameOfVariableToCapture %}Hello My Attribution{% endcapture %}
  
---------------------------------------------  
    
MarkDown - numbered list  
  https://stackoverflow.com/questions/18088955/markdown-continue-numbered-list  
  
HTML - ordered list - start  
HTML \<ol\> start Attribute  
  https://www.w3schools.com/tags/att_ol_start.asp  
HTML \<li\> Tag  
  https://www.w3schools.com/tags/tag_li.asp  
  
    4 spaces  
  
---------------------------------------------  
  
---------------------------------------------  
end of file    
