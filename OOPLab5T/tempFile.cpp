//namespace Exp5 {
//	class Base {
//		int data_base;
//	public:
//		Base() {
//			cout << " Base Ctor " << endl;
//		}
//		Base(Base& s) {
//			data_base = s.data_base;
//			cout << " Base copy Ctor " << endl;
//		}
//		Base(int in) : data_base(in) {
//			cout << " Base Ctor " << endl;
//		}
//		void Show() {
//			cout << " Base Show " << endl;
//		}
//		Base& operator=(const Base& s) {
//			data_base = s.data_base;
//			return *this;
//		}
//
//		virtual ~Base() {
//			cout << " Base Dtor " << endl;
//		}
//	};
//
//	class Drv : public Base {    // 1)  public  2) protected 
//		int data_drv;
//	public:
//		Drv() {
//			cout << " Drv Ctor " << endl;
//		}
//		Drv(Drv& s) {
//			cout << " Drv copy Ctor " << endl;
//		}
//		void Show() {
//			cout << " Drv Show " << endl;
//		}
//		~Drv() {
//			cout << " Drv Dtor " << endl;
//		}
//		Drv& operator=(const Base& s) {
//			this->Base::operator=(s);
//			data_drv = 0;
//			return *this;
//		}
//
//	};
//	class D2 : public Drv {
//		int data_drv;
//	public:
//		D2() {
//			cout << " D2 Ctor " << endl;
//		}
//		D2(D2& s) {
//			cout << " D2 vcopy Ctor " << endl;
//		}
//		void Show() {
//			cout << " D2 Show " << endl;
//		}
//		~D2() {
//			cout << " D2 Dtor " << endl;
//		}
//	};
//	void Proc(Base a)
//	{
//		a.Show();
//	}
//	void Proc(Base&& a)
//	{
//		a.Show();
//	}
//	void Proc(Base* a)
//	{
//		a->Show();
//	}
//
//
//	int Exp5main()
//	{
//		cout << " Test: The sequence of the call to \n the designers and destructors! \n";
//		cout << " Createting  D2  obj \n";
//		Base* pobj;
//		pobj = new D2;
//		cout << " D2  obj (new) is craete \n";
//		cout << " Call Proc(pobj);  \n";
//		Proc(pobj);
//		delete pobj;
//		D2 obj;
//		cout << " D2  obj  is craete \n";
//		cout << " Call Proc(obj);  \n";
//		Proc(obj);
//
//		cout << "\n\n Test call function  \n\n";
//		Base b, * bp = &b;
//		Drv  d, * dp = &d;
//		D2   d2, * d2p = &d2;
//		cout << "b \n";
//		Proc(b);
//		Proc(bp);
//		cout << "d \n";
//		Proc(d);
//		Proc(dp);
//		cout << "d2 \n";
//		Proc(d2);
//		Proc(d2p);
//		d = b;
//		return 0;
//	}
//
//}