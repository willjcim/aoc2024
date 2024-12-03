#include <format>
#include <fstream> 
#include <iostream>
#include <vector>


using namespace std;


template<typename T>
struct timer;

template<typename R, typename... Args>
struct timer<R(*)(Args...)>
{
	using fn = R(*)(Args...);

	static R time(fn func, Args... args)
	{
		auto start = chrono::high_resolution_clock::now();
		R retval = func(args...);
		auto stop = chrono::high_resolution_clock::now();

		auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

		cout << format("Func took {} milliseconds", duration.count()) << endl;

		return retval;
	}
};

// auto ret = timer<decltype(&func)>::time(func, args....) 
// i.e. auto part1 = timer<decltype(&Part1)>::time(Part1, inputText);
 