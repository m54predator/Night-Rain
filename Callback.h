class Callback{
private:

	// �����, �������������� ����� ������� � �� �������������
	class FuncClass{
	public:
		// ���������������� �������
		virtual void Call(int) = 0;
	};

	// ��������� �� ���������� �����
	FuncClass *function;

public:
	
	Callback(){
		function = nullptr;
	}

	~Callback(){
		if (function) delete function;
	}

	template<class T, class C>
	void operator=(T func){
		if (function) delete function;

		// ����� � ��������������� �������� Call, ���������� func
		class NewFuncClass :public FuncClass{
		public:
			T func;

			NewFuncClass(T f) :func(f){
			}

			void Call(C d){
				func(d);
			}
		};

		// ������ ��������� ������ � ��������� ���
		function = new NewFuncClass(func);
	
		void operator()(C d){
			if (function) function->Call(d);
		}
	}
};