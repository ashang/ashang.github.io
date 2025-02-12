#include <stdio.h>
#include <iostream>
#include <string>

class A {
public:
	A(const char* str) { m_str = str; }
	virtual ~A() {}
	virtual void Foo(int n, int m) {
		printf("A %d %d %hs\n", n, m, m_str.c_str());
	}
protected:
	std::string m_str;
};

class A2 {
public:
	A2(const char* str) { m_str = str; }
	virtual ~A2() {}
	virtual void Foo(int n, int m) {
		printf("A2 %d %d %hs\n", n, m, m_str.c_str());
	}
protected:
	std::string m_str;
};

class A3 {
public:
	A3(const char* str) { m_str = str; }
	virtual ~A3() {}
	virtual void Foo(int n, int m) {
		printf("A3 %d %d %hs\n", n, m, m_str.c_str());
	}
protected:
	std::string m_str;
};


class B : public A {
public:
	B(const char* str) : A(str) { }
	virtual ~B() {}
	virtual void Foo(int n, int m) {
		printf("B %d %d %hs\n", n, m, m_str.c_str());
	}
};

class C : public A, public A2 {
public:
	C(const char* str) : A(str), A2(str) { }
	virtual ~C() {}
	virtual void Foo(int n, int m) {
		printf("C %d %d %hs %hs\n", n, m, A::m_str.c_str(), A2::m_str.c_str());
	}
};

class D : public A, public A2, public A3 {
public:
	D(const char* str) : A(str), A2(str), A3(str) { }
	virtual ~D() {}
	virtual void Foo(int n, int m) {
		printf("D %d %d %hs %hs %hs\n", n, m, A::m_str.c_str(), A2::m_str.c_str(), A3::m_str.c_str());
	}
};

class E : public C, public D {
public:
	E(const char* str) : C(str), D(str) {}
	virtual ~E() {}
	virtual void Foo(int n, int m) {
		printf("E %d %d %hs %hs %hs\n", n, m, A::m_str.c_str(), A2::m_str.c_str(), A3::m_str.c_str());
	}
};

typedef void (A::*AFooPointer)(int, int);
typedef void (B::*BFooPointer)(int, int);
typedef void (C::*CFooPointer)(int, int);
typedef void (D::*DFooPointer)(int, int);
typedef void (E::*EFooPointer)(int, int);

int main()
{
	printf("---- normal call ----\n");
	A a("AAA");
	B b("BBB");
	C c("CCC");
	D d("DDD");
	E e("EEE");
	a.Foo(100, 200);
	b.Foo(300, 400);
	c.Foo(500, 600);
	d.Foo(700, 800);
	e.Foo(900, 1000);

	printf("\n");
	printf("---- call by pointer ----\n");
	AFooPointer pa = &A::Foo;
	BFooPointer pb = &B::Foo;
	CFooPointer pc = &C::Foo;
	CFooPointer pc1 = &A::Foo;
	CFooPointer pc2 = &A2::Foo;
	DFooPointer pd = &D::Foo;
	DFooPointer pd1 = &A::Foo;
	DFooPointer pd2 = &A2::Foo;
	DFooPointer pd3 = &A3::Foo;
	EFooPointer pe = &E::Foo;
	(a.*pa)(10, 20);  // A 10 20 AAA
	// (a.*pb)();     // Incorrect. B::BFooPointer can't behave as A::Foo
	(b.*pa)(30, 40);  // B 30 40 BBB (because it's virtual)
	(b.*pb)(50, 60);  // B 50 60 BBB
	(c.*pc)(1, 2);    // C 1 2 CCC
	(c.*pc1)(3, 4);   // C 3 4 CCC
	(c.*pc2)(5, 6);   // C 5 6 CCC
	(d.*pd)(7, 8);    // D 7 8 CCC
	(d.*pd1)(9, 10);  // D 9 10 CCC
	(d.*pd2)(11, 12); // D 11 12 CCC
	(d.*pd2)(13, 14); // D 13 14 CCC
	(e.*pe)(15, 16);  // E 15 16 EEE EEE EEE

	printf("\n");
	printf("---- pointer size ----\n");
	printf("sizeof(pa):%d\n", sizeof(pa));
	printf("sizeof(pb):%d\n", sizeof(pb));

	printf("sizeof(pc):%d\n", sizeof(pc)); // 8!!!!!!!!!!!!!!!
	printf("sizeof(pc1):%d\n", sizeof(pc)); // 8!!!!!!!!!!!!!!!
	printf("sizeof(pc2):%d\n", sizeof(pc)); // 8!!!!!!!!!!!!!!!

	printf("sizeof(pd):%d\n", sizeof(pd)); // 8!!!!!!!!!!!!!!!
	printf("sizeof(pd1):%d\n", sizeof(pd1)); // 8!!!!!!!!!!!!!!!
	printf("sizeof(pd2):%d\n", sizeof(pd2)); // 8!!!!!!!!!!!!!!!
	printf("sizeof(pd3):%d\n", sizeof(pd3)); // 8!!!!!!!!!!!!!!!

	printf("sizeof(pe):%d\n", sizeof(pe)); // 8!!!!!!!!!!!!!!!

	printf("sizeof(void*):%d\n", sizeof(void*));
}
