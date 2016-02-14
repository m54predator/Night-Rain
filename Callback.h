class Callback{
private:

	// Класс, обеспечивающий вызов функций с их особенностями
	class FuncClass{
	public:
		// Переопределяемая функция
		virtual void Call(int) = 0;
	};

	// Указатель на сохранённый класс
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

		// Класс с переопределённой функцией Call, вызывающей func
		class NewFuncClass :public FuncClass{
		public:
			T func;

			NewFuncClass(T f) :func(f){
			}

			void Call(C d){
				func(d);
			}
		};

		// Создаём экземпляр класса и сохраняем его
		function = new NewFuncClass(func);
	
		void operator()(C d){
			if (function) function->Call(d);
		}
	}
};