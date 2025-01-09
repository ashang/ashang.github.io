---
title: Code Block Test
date: 2021-06-27 09:00:00
tags:
    - test
    - Jekyll
    - markdown
    - code block
---

## Code Spans

Use `<html>` tags for this.

Here is a literal `` ` `` backtick.
And here is ``  `some`  `` text (note the two spaces so that one is left
in the output!).

```js
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
```

```javascript
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
```

<!--more-->

**markdown:**

    Here is a literal `` ` `` backtick.
    And here is ``  `some`  `` text (note the two spaces so that one is left
    in the output!).

## Standard Code Blocks

    Here comes some code

    This text belongs to the same code block.

^
    This one is separate.

**markdown:**

```
    Here comes some code

    This text belongs to the same code block.

^
    This one is separate.
```

---

```
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
```

**markdown:**

    ```
    (() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
    ```

---

```javascript
(() => console.log('hello, world!'))();
```

**markdown:**

    ```javascript
    (() => console.log('hello, world!'))();
    ```

---

```none
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
```

## Highlighting Code Snippets

{% highlight javascript %}
(() => console.log('hello, world!'))();
{% endhighlight %}

**markdown:**

```
{%- raw -%}
{% highlight javascript %}
(() => console.log('hello, world!'))();
{% endhighlight %}
{% endraw %}
```

### Line Numbers

{% highlight javascript linenos %}
var hello = 'hello';
var world = 'world';
var space = ' ';
(() => console.log(hello + space + world + space + hello + space + world + space + hello + space + world + space + hello + space + world))();
{% endhighlight %}

**markdown:**

```
{%- raw -%}
{% highlight javascript linenos %}
var hello = 'hello';
var world = 'world';
var space = ' ';
(() => console.log(hello + space + world + space + hello + space + world + space + hello + space + world + space + hello + space + world))();
{% endhighlight %}
{% endraw %}
```

---

{% highlight javascript %}
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
{% endhighlight %}

{% highlight none %}
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
{% endhighlight %}

## Fenced Code Blocks

~~~
Here comes some code.
~~~

**markdown:**

    ~~~
    Here comes some code.
    ~~~

---

~~~~~~~~~~~~
~~~~~~~
code with tildes
~~~~~~~~
~~~~~~~~~~~~~~~~~~

**markdown:**

    ~~~~~~~~~~~~
    ~~~~~~~
    code with tildes
    ~~~~~~~~
    ~~~~~~~~~~~~~~~~~~

## Language of Code Blocks

~~~
def what?
  42
end
~~~
{: .language-ruby}

**markdown:**

    ~~~
    def what?
      42
    end
    ~~~
    {: .language-ruby}

---

~~~ ruby
def what?
  42
end
~~~

**markdown:**

    ~~~ ruby
    def what?
      42
    end
    ~~~
```c
if (barebones.surge(smsBitmap, ethics_rpc) == flowchart_vpi) {
    xmlHeader(networkingHdtv);
    parse_windows_bar.requirements_only = ftp_compatible;
} else {
    faq = linkedin;
}
if (sampling <= bar) {
    controlFloodTooltip(correctionFilename(radcab), smtp);
    css.nanometer_dial = subdirectoryMacroSupply(t_drive, ctr *
            parallel_hard, num + voip_hard_hfs);
}
if (responsive(modem_cross_hub, kibibyte_bank(newsgroup_rpm_prompt +
        systemPaperAddress, whiteIn + power_ascii_file, -5))) {
    sramDirect += daemon + 12;
    card_warm_dfs = hubDevelopment;
    payloadBot = web.end.kilohertzTerahertzFirmware(logic_io_engine, sql +
            eps);
}
skyscraper /= bare_ultra + 3;
brouterMiniRgb = 2;
```

{% highlight c %}
#include <stdio.h>

//Function declarations
int is_prime(int n);
void goldbach(int g);

int main(){
	int number = 0;
	while(1){
		printf("Enter even number:");
		scanf("%d",&number);
		if(number>2 && number%2==0){
			goldbach(number);
		}
		else{
			printf("Incorrect number!");
		}
		printf("");
	}
	return 0;
}

{% endhighlight %}





`String`

Using indents:

    text
    text
    text


Fenced code block:

```
text
text
<tag>
```

Fenced code block with language (lineNumbersInTable = false):

```Java
// JavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJavaJava
public final class String
    implements java.io.Serializable, Comparable<String>, CharSequence
{
    /** The value is used for character storage. */
    private final char value[];

    /** The offset is the first index of the storage that is used. */
    private final int offset;

    /** The count is the number of characters in the String. */
    private final int count;

    /** Cache the hash code for the string */
    private int hash; // Default to 0

    // ...

    // Package private constructor which shares value array for speed.
    String(int offset, int count, char value[]) {
        this.value = value;
        this.offset = offset;
        this.count = count;
    }

    // ...

    /**
     * Returns a new string that is a substring of this string. The
     * substring begins at the specified <code>beginIndex</code> and
     * extends to the character at index <code>endIndex - 1</code>.
     * Thus the length of the substring is <code>endIndex-beginIndex</code>.
     * <p>
     * Examples:
     * <blockquote><pre>
     * "hamburger".substring(4, 8) returns "urge"
     * "smiles".substring(1, 5) returns "mile"
     * </pre></blockquote>
     *
     * @param      beginIndex   the beginning index, inclusive.
     * @param      endIndex     the ending index, exclusive.
     * @return     the specified substring.
     * @exception  IndexOutOfBoundsException  if the
     *             <code>beginIndex</code> is negative, or
     *             <code>endIndex</code> is larger than the length of
     *             this <code>String</code> object, or
     *             <code>beginIndex</code> is larger than
     *             <code>endIndex</code>.
     */
    public String substring(int beginIndex, int endIndex) {
        if (beginIndex < 0) {
            throw new StringIndexOutOfBoundsException(beginIndex);
        }
        if (endIndex > count) {
            throw new StringIndexOutOfBoundsException(endIndex);
        }
        if (beginIndex > endIndex) {
            throw new StringIndexOutOfBoundsException(endIndex - beginIndex);
        }
        return ((beginIndex == 0) && (endIndex == count)) ? this :
            new String(offset + beginIndex, endIndex - beginIndex, value);
    }

    // ...
}
```

Using hugo's `highlight` [shortcode]([highlight](https://gohugo.io/content-management/syntax-highlighting/#highlight-shortcode)) (lineNumbersInTable = true):

{% raw %}
{{< highlight typescript "linenos=table, hl_lines=8 18-21" >}}
// TypeScript
type OptionalUser = {
    [K in keyof User]?: User[K]
}

// ! we can remove optional constraint
type RequiredUser = {
    [K in keyof OptionalUser]-?: User[K]
}

type NullableUser = {
    [K in keyof User]: User[K] | null
}
type ReadonlyUser = {
    readonly [K in keyof User]: User[K]
}

// ! we can remove readonly constraint
type ModifiableUser = {
    -readonly [K in keyof User]: User[K]
}
{{< endhighlight >}}
{% endraw %}

Without line number

{% raw %}
{{< highlight javascript "linenos=false" >}}
(() => {

  function createCopyButton(codeNode) {
    const copyBtn = document.createElement('button')
    copyBtn.className = 'code-copy-btn'
    copyBtn.type = 'button'
    copyBtn.innerText = 'copy'
    copyBtn.parentElement = codeNode.parentElement

    let resetTimer
    copyBtn.addEventListener('click', () => {
      navigator.clipboard.writeText(codeNode.innerText).then(() => {
        copyBtn.innerText = 'copied!'
      }).then(() => {
        clearTimeout(resetTimer)
        resetTimer = setTimeout(() => {
          copyBtn.innerText = 'copy'
        }, 1000)
      })
    })

    return copyBtn
  }

  document.querySelectorAll('pre > code').forEach((codeNode) => {
    const copyBtn = createCopyButton(codeNode);
    codeNode.parentNode.insertBefore(copyBtn, codeNode)
  })

})()
{{< endhighlight >}}
{% endraw %}

## Code Spans

Use `<html>` tags for this.

Here is a literal `` ` `` backtick.
And here is ``  `some`  `` text (note the two spaces so that one is left
in the output!).

```javascript
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
```

<!--more-->

**markdown:**

    Here is a literal `` ` `` backtick.
    And here is ``  `some`  `` text (note the two spaces so that one is left
    in the output!).

## Standard Code Blocks

    Here comes some code

    This text belongs to the same code block.

^
    This one is separate.

**markdown:**

```
    Here comes some code

    This text belongs to the same code block.

^
    This one is separate.
```

---

```
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
```

**markdown:**

    ```
    (() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
    ```

---

```javascript
(() => console.log('hello, world!'))();
```

**markdown:**

    ```javascript
    (() => console.log('hello, world!'))();
    ```

---

```none
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
```

## Highlighting Code Snippets

{% highlight javascript %}
(() => console.log('hello, world!'))();
{% endhighlight %}

**markdown:**

```
{%- raw -%}
{% highlight javascript %}
(() => console.log('hello, world!'))();
{% endhighlight %}
{% endraw %}
```

### Line Numbers

{% highlight javascript linenos %}
var hello = 'hello';
var world = 'world';
var space = ' ';
(() => console.log(hello + space + world + space + hello + space + world + space + hello + space + world + space + hello + space + world))();
{% endhighlight %}

**markdown:**

```
{%- raw -%}
{% highlight javascript linenos %}
var hello = 'hello';
var world = 'world';
var space = ' ';
(() => console.log(hello + space + world + space + hello + space + world + space + hello + space + world + space + hello + space + world))();
{% endhighlight %}
{% endraw %}
```

---

{% highlight javascript %}
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
{% endhighlight %}

{% highlight none %}
(() => console.log('hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world! hello, world!'))();
{% endhighlight %}

## Fenced Code Blocks

~~~
Here comes some code.
~~~

**markdown:**

    ~~~
    Here comes some code.
    ~~~

---

~~~~~~~~~~~~
~~~~~~~
code with tildes
~~~~~~~~
~~~~~~~~~~~~~~~~~~

**markdown:**

    ~~~~~~~~~~~~
    ~~~~~~~
    code with tildes
    ~~~~~~~~
    ~~~~~~~~~~~~~~~~~~

## Language of Code Blocks

~~~
def what?
  42
end
~~~
{: .language-ruby}

**markdown:**

    ~~~
    def what?
      42
    end
    ~~~
    {: .language-ruby}

---

~~~ ruby
def what?
  42
end
~~~

**markdown:**

    ~~~ ruby
    def what?
      42
    end
    ~~~

## Is prime

{% highlight c %}
#include <stdio.h>

//Function declarations
int is_prime(int n);
void goldbach(int g);

int main(){
	int number = 0;
	while(1){
		printf("Enter even number:");
		scanf("%d",&number);
		if(number>2 && number%2==0){
			goldbach(number);
		}
		else{
			printf("Incorrect number!");
		}
		printf("");
	}
	return 0;
}
{% endhighlight %}

## Binary search

{% highlight c %}
#include <stdio.h>
int main()
{
	int array[11] = {2,3,4,5,6,7,8,9,22,33,45};
	int low       = 0;
	int high   	  = 10;
	int flag      = 0;
	int s         = 4;
	
	while(low <= high){
		int index = low+(high-low)/2;
		if(array[index] == s){
			flag = 1;
			printf("Founded: %d \n",index);
			break;
		}
		else if(array[index] < s){
			low   = index+1;
		}
		else{
			high = index-1;
		}
	}
	if(flag == 0){
		printf("Not Found!\n");
	}

	return 0;
}
{% endhighlight %}

