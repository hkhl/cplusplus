#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/*
 * 思路:  用到哪些东西
 *构造一个vector        对用应三种构造函数
 *vector<int> vs;
 *vector<double> v(100);
 *vector<int> vc(10, 100);
 *
 *获得vecotr使用的类型的名字
 *vector<int>::const_iterator b, e;
 *vector<int>::size_type i = 0;
 *
 *用size函数与索引值查看vector中元素
 *for (int i = 0; i != vs.size(); i++)
 *    cout << vs[i];
 *
 *b = vs.begin();
 *e = vs.end();
 *
 *实现简单vector类
 *
 */


//push_back
//clear
//back_inserter()

//类的创建 赋值 销毁
vector<int>v;
template <class T> class vec
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    //构造函数
    vec(){create();}
    explicit vec(size_type n, const T& val = T()){creat(n, val);}
    //复制构造函数   从一个已经存在的对象中"复制"每个元素到新的对象中
    vec(const vec &v){create(v.being, v.end());}
    //析构函数
    ~vec(){ uncreate(); }



    //赋值运算符重载函数
    //vec<T>& vec<T>::operator=(const vec& rhs); //类外这样写 必须有<T>
    vec& operator=(const vec &rhs);
    T& operator [] (size_type i) {return data[i];}

    size_type size() const {return limit - data; }
    iterator begin(){return data;}
    const_iterator begin() const {return data;}
    iterator end(){return limit;}
    const_iterator end() const {return limit;}

    //vector 插入操作
    void push_back(const T& val)
    {
        if (avail == limit)      //空间占满
            grow();
        unchecked_append(val);   //将新增加的元素添加到末端
    }

private:
    //T* data;  //vec首元素
    //T* limit; //vec末元素

    iterator data;    //指向第一个元素
    iterator avail;   //指向最后一个初始化的元素的下一个
    iterator limit;   //指向vector空间的最后一个的下一个


    //内存分配工具
    allocator<T> alloc;   //控制内存分配的对象

    //为底层的数组分配空间并对它进行初始化
     void create();
     void create(size_type, const T&);
     void create(const_iterator, const_iterator);

     //删除数组中的元素并释放其占用的内存
     void uncreate();

     //支持push_back的函数
     void grow();
     void unchecked_append(const T&);
};

//实现私有成员函数需要满足以下类不变式, 任何情况必须满足以下4条

/*
 * 1. 如果对象中有数据元素的话, data指向对象数组首元素, 否则为零(不存在元素)
 * 2. data <= avail <= limit
 * 3. 在[data, avail) 区间内的元素是被初始化的
 * 4. 在[avail, limit)区间内的元素未被初始化
 */



//分配内存并初始化
template <class T> void vec<T>::create() //仅仅生成一个vec类型对象
{
    data = avail = limit = 0;
}

template <class T> void vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocte(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val); //将data到limit之间初始化
}

template <class T>
void vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j-i);
    limit = avail = uninitialized_copy(i, j, data);
}

//析构函数, 删除对象, 释放占用内存
template <class T> void vec<T>::uncreate()
{
    if (data)     //需要判断是否为空, 但是delete不需要, 删除零指针不产生错误
    {  //(以相反的顺序)删除构暂函数生成的元素
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);

        //返回占用的所有内存空间
        alloc.deallocate(data, limit - data);
    }
    //重置指针以表明vec类型对象为空
    data = limit = avail = 0;
}

//实现使用push_back函数的成员函数
//grow的任务是分配足够大的内存空间, 至少2倍
template <class T> void vec<T>::grow()
{
    //在扩展对象大小时, 为对象分配两倍大小的内存空间
    size_type new_size = max(2*(limit-data), ptrdiff_t(1));  //这里是防止开始没有分配内存空间, 选择一个元素空间和2倍当前空间中较大的分配
    //分配新的内存空间并将已存在的对象元素内容复制到新内存中
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);
    //返回原来的内存空间
    uncreate();
    //重置指针, 使其指向新分配的内存空间
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

//假设avail指向一片新分配但尚未被初始化的内存空间 (push_bakc插入元素)
template <class T> void vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}



//赋值运算符重载函数
template <class T>
vec<T>& vec<T>::operator=(const vec& rhs)
{
    //判断是否自我赋值   如果是同一个对象,那就用一个地址不需要开辟新的地址
    if (&rhs != this)
    {
        //删除运算符左侧的数数组
        uncreate();
        //从右侧复制元素到左侧
        create(rhs.begin(), rhs.end());
    }
    return *this;
}
int main()
{
    vec<int> s;

    s.push_back(5);
    s.push_back(7);
    s.push_back(8);
    s.push_back(9);

    for(vec<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}

/*
 内存管理
<memory> 头文件中提供了一个名为allocator<T>的类,可以分配一块预备用来储存T类型对象
但是尚未被初始化的内存块, 并返回一个指向这块内存块的头元素的指针.


template <class T> class allocator
{
public:
    T* allocate(size_t);        //用来分配一块被指定却未初始化的内存块
    void deallocate(T*, size_t);//释放未被初始化的内存, 一个是allocate返回的指针, 一个是内存块大小
    void construct(T*, T);      //用来在allocate申请飞的内存上进行初始化 生成单个对象  一个是allocate返回指针, 一个是用来复制到指针指向的内存块的对象值
    void destroy(T*);           //用来删除这个对象
};
void uninitialized_fill(T*, T*, const T&);  //对allocate分配内存某一区域进行填充
T* uninitialized_copy(T*, T*, T*);          //将前两个地址内容复制到第三个内存块中
*/


    //复制构造函数   从一个已经存在的对象中"复制"每个元素到新的对象中
    //但是这里就有了浅拷贝和深拷贝的问题(当成员变量有指针的时候)
    //仅仅是拷贝了指针变量 data 和 limit, 新对象和原对象操作的内存空间一毛一样
    //很明显存在问题, 我们希望的是两个独立的地址空间
    //所以我们应该使用深拷贝  开辟新的空间
    //vec(const vec &v){create(v.being, v.end());}



 *    //explicit 关键字只在定义一个参数的构暂函数的时候才有意义,
 *    //并且.如果定义了这样一个构造函数,那么编译器只有在用户显示的使用
 *    //构造函数才会有作用 如: vec v(100)
 *    //而像这样 vec v = 100 错误
