
last update : 20221110_0343(UTC+8)   
  
prev update : 20221109_2043(UTC+8)  
  
---------------------------------------------  
  
How to write in Markdown  
  https://developer.mozilla.org/en-US/docs/MDN/Writing_guidelines/Howto/Markdown_in_MDN  
  
GitHub Flavored Markdown Spec  
  https://github.github.com/gfm/  
  
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
  
inline :  $\sum_{n=1}^{10} n^2$  
    
  
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
  
MarkDown - numbered list  
  https://stackoverflow.com/questions/18088955/markdown-continue-numbered-list  
  
HTML - ordered list - start  
HTML \<ol\> start Attribute  
  https://www.w3schools.com/tags/att_ol_start.asp  
HTML \<li\> Tag  
  https://www.w3schools.com/tags/tag_li.asp  
HTML DOM Variable Object  
  https://www.w3schools.com/jsref/dom_obj_var.asp  
HTML try it  
  https://www.w3schools.com/jsref/tryit.asp?filename=tryjsref_var_create  
HTML type "p"  
  \<p\> HTML element represents a paragraph  
HTML type "pre"  
  \<pre\> HTML element represents preformatted text  
  
What does \<!-- --\> in html mean ?   Ans : comments  
  https://stackoverflow.com/questions/30130324/what-does-in-html-mean  
  https://www.tutorialspoint.com/html/html_comments.htm  
  https://html.spec.whatwg.org/multipage/syntax.html#comments  
  
  
---------------------------------------------  
  
0+2 spaces  
  
 1+2 spaces  
  
  2+2 spaces  
  
   3+2 spaces  
  
    4+2 spaces  
  
     5+2 spaces  
  
      6+2 spaces  
  
       7+2 spaces  
  
        8+2 spaces  
  
---------------------------------------------  
  
Variable tags create new Liquid variables.  
  https://shopify.github.io/liquid/tags/variable/  
  https://shopify.github.io/liquid/  
	{% capture my_variable %}I am being captured.{% endcapture %}  
	{{ my_variable }}  
	{% assign var = 10 %}  
	{% increment var %}  
	{% increment var %}  
	{% increment var %}  
	{{ var }}  
  
Variables in Markdown  
  https://github.com/bdougie/variables-in-markdown/blob/master/README.md  
  https://www.brianchildress.co/variables-in-markdown/  
  https://en.wikipedia.org/wiki/Mustache_(template_system)  
  
---  
<!--#
NOUN=mother
ATTRIBUTION=Mark Wahlberg
$-->

"Say hi to your {{NOUN}} for me," {{ATTRIBUTION}} {{nameOfVariableToCapture}}  
  
{% capture nameOfVariableToCapture %}Hello My Attribution{% endcapture %}  
  
---------------------------------------------  
  
---------------------------------------------  
end of file    
