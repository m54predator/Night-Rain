#ifndef _CALLBACK_H
#define _CALLBACK_H
template<class C, class B>
class Callback{
private:

	// Класс, обеспечивающий вызов функций с их особенностями
	class FuncClass{
	public:
		// Переопределяемая функция
		virtual void Call(C,B) = 0;
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

	template<class T>
	void operator=(T func){
		if (function) delete function;

		// Класс с переопределённой функцией Call, вызывающей func
		class NewFuncClass :public FuncClass{
		public:
			T func;

			NewFuncClass(T f) :func(f){
			}

			void Call(C d, B b){
				func(d,b);
			}
		};

		// Создаём экземпляр класса и сохраняем его
		function = new NewFuncClass(func);

		}
	void operator()(C d, B b){
		if (function) function->Call(d,b);
	}
};
#endif