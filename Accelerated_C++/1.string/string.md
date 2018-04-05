https://blog.csdn.net/sinat_20265495/article/details/52502315
#include <string>

插入字符串
insert()函数可以在string字符串中指定的位置插入另一个字符串，它的一种原型为：
string& insert (size_t pos, const string& str);
pos 表示要插入的位置，也就是下标；str 表示要插入的字符串，它可以是 string 变量，也可以是C风格的字符串
insert() 函数的第一个参数有越界的可能，如果越界，则会产生运行时异常





删除字符串
erase() 函数可以删除 string 变量中的一个子字符串。它的一种原型为：
string& erase (size_t pos = 0, size_t len = npos);
pos 表示要删除的子字符串的起始下标，len 表示要删除子字符串的长度。如果不指明 len 的话，那么直接删除从 pos 到字符串结束处的所有字符（此时 len = str.length - pos）。

在 pos 参数没有越界的情况下， len 参数也可能会导致要删除的子字符串越界。但实际上这种情况不会发生，erase() 函数会从以下两个值中取出最小的一个作为待删除子字符串的长度：
len 的值；
字符串长度减去 pos 的值。

说得简单一些，待删除字符串最多只能删除到字符串结尾。





提取子字符串
substr() 函数用于从 string 字符串中提取子字符串，它的原型为：
string substr (size_t pos = 0, size_t len = npos) const;
pos 为要提取的子字符串的起始下标，len 为要提取的子字符串的长度。
系统对 substr() 参数的处理和 erase() 类似：
如果 pos 越界，会抛出异常；
如果 len 越界，会提取从 pos 到字符串结尾处的所有字符。




字符串查找
string 类提供了几个与字符串查找有关的函数，如下所示。
find() 函数
find() 函数用于在 string 字符串中查找子字符串出现的位置，它其中的两种原型为：
size_t find (const string& str, size_t pos = 0) const;
size_t find (const char* s, size_t pos = 0) const;
第一个参数为待查找的子字符串，它可以是 string 变量，也可以是C风格的字符串。第二个参数为开始查找的位置（下标）；如果不指明，则从第0个字符开始查找。

rfind() 函数
rfind() 和 find() 很类似，同样是在字符串中查找子字符串，不同的是 find() 函数从第二个参数开始往后查找，而 rfind() 函数则最多查找到第二个参数处，如果到了第二个参数所指定的下标还没有找到子字符串，则返回一个无穷大值4294967295。

find_first_of() 函数
find_first_of() 函数用于查找子字符串和字符串共同具有的字符在字符串中首次出现的位置







a)    string s;  //生成一个空字符串s
b)    string s(str) //拷贝构造函数 生成str的复制品
c)    string s(str,stridx) //将字符串str内“始于位置stridx”的部分当作字符串的初值
d)    string s(str,stridx,strlen) //将字符串str内“始于stridx且长度顶多strlen”的部分作为字符串的初值
e)    string s(cstr) //将C字符串作为s的初值
f)    string s(chars,chars_len) //将C字符串前chars_len个字符作为字符串s的初值。
g)    string s(num,c) //生成一个字符串，包含num个c字符
h)    string s(beg,end) //以区间beg;end(不包含end)内的字符作为字符串s的初值
i)    s.~string() //销毁所有字符，释放内存



字符串操作函数 这里是C++字符串的重点，我先把各种操作函数罗列出来，不喜欢把所有函数都看完的人可以在这里找自己喜欢的函数，再到后面看他的详细解释。

a) =,assign()   //赋以新值
b) swap()   //交换两个字符串的内容
c) +=,append(),push_back() //在尾部添加字符
d) insert() //插入字符
e) erase() //删除字符
f) clear() //删除全部字符
g) replace() //替换字符
h) + //串联字符串
i) ==,!=,<,<=,>,>=,compare()  //比较字符串
j) size(),length()  //返回字符数量
k) max_size() //返回字符的可能最大个数
l) empty()  //判断字符串是否为空
m) capacity() //返回重新分配之前的字符容量
n) reserve() //保留一定量内存以容纳一定数量的字符
o) [ ], at() //存取单一字符
p) >>,getline() //从stream读取某值
q) <<  //将谋值写入stream
r) copy() //将某值赋值为一个C_string
s) c_str() //将内容以C_string返回
t) data() //将内容以字符数组形式返回
u) substr() //返回某个子字符串
v)查找函数
w)begin() end() //提供类似STL的迭代器支持
x) rbegin() rend() //逆向迭代器
y) get_allocator() //返回配置器










begin 得到指向字符串开头的Iterator
end 得到指向字符串结尾的Iterator
rbegin 得到指向反向字符串开头的Iterator
rend 得到指向反向字符串结尾的Iterator
size 得到字符串的大小
length 和size函数功能相同
max_size 字符串可能的最大大小
capacity 在不重新分配内存的情况下，字符串可能的大小
empty 判断是否为空
operator[] 取第几个元素，相当于数组
c_str 取得C风格的const char* 字符串
data 取得字符串内容地址
operator= 赋值操作符
reserve 预留空间
swap 交换函数
insert 插入字符
append 追加字符
push_back 追加字符
operator+= += 操作符
erase 删除字符串
clear 清空字符容器中所有内容
resize 重新分配空间
assign 和赋值操作符一样
replace 替代
copy 字符串到空间
find 查找
rfind 反向查找
find_first_of 查找包含子串中的任何字符，返回第一个位置
find_first_not_of 查找不包含子串中的任何字符，返回第一个位置
find_last_of 查找包含子串中的任何字符，返回最后一个位置
find_last_not_of 查找不包含子串中的任何字符，返回最后一个位置
substr 得到字串
compare 比较字符串
operator+ 字符串链接
operator== 判断是否相等
operator!= 判断是否不等于
operator< 判断是否小于
operator>> 从输入流中读入字符串
operator<< 字符串写入输出流
getline 从输入流中读入一行


比较函数
比较函数 C++字符串支持常见的比较操作符（>,>=,<,<=,==,!=），甚至支持string与C-string的比较(如 str<”hello”)。在使用>,>=,<,<=这些操作符的时候是根据“当前字符特性”将字符按字典顺序进行逐一得比较。字典排序靠前的字符小，比较的顺序是从前向后比较，遇到不相等的字符就按这个位置上的两个字符的比较结果确定两个字符串的大小。同时，string(“aaaa”) <string(aaaaa)。 另一个功能强大的比较函数是成员函数compare()。他支持多参数处理，支持用索引值和长度定位子串来进行比较。他返回一个整数来表示比较结果，返回值意义如下：0-相等 〉0-大于 <0-小于。举例如下：
string s(“abcd”);
s.compare(“abcd”); //返回0
s.compare(“dcba”); //返回一个小于0的值
s.compare(“ab”); //返回大于0的值
s.compare(s); //相等
s.compare(0,2,s,2,2); //用”ab”和”cd”进行比较 小于零
s.compare(1,2,”bcx”,2); //用”bc”和”bc”比较。


赋值函数
s.assign(str); //直接
s.assign(str,1,3);//如果str是”iamangel” 就是把”ama”赋给字符串
s.assign(str,2,string::npos);//把字符串str从索引值2开始到结尾赋给s
s.assign(“gaint”); //不说
s.assign(“nico”,5);//把’n’ ‘I’ ‘c’ ‘o’ ‘\0’赋给字符串
s.assign(5,’x’);//把五个x赋给字符串





把字符串清空的方法有三个：s=””;s.clear();s.erase();



替换函数
string s=”il8n”;
s.replace(1,2,”nternationalizatio”);
//从索引1开始的2个字符替换成后面的C_string
替换后internationalization

s.erase(13);//从索引13开始往后全删除
s.erase(7,5);//从索引7开始往后删5个

