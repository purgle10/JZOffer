// main.cpp

#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
#include <stack>

#include "MemoryPool.h"
#include "StackAlloc.h"

// 根据电脑性能调整这些值
// 插入元素个数
#define ELEMS 250000
// 重复次数
#define REPS 50

int main()
{
	clock_t start;

	// 使用默认分配器
	StackAlloc<int, std::allocator<int> > stackDefault;
	start = clock();
	for (int j = 0; j < REPS; j++) {
		assert(stackDefault.empty());
		for (int i = 0; i < ELEMS; i++)
			stackDefault.push(i);
		for (int i = 0; i < ELEMS; i++)
			stackDefault.pop();
	}
	std::cout << "Default Allocator Time: ";
	std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";

	// 使用stack
	std::stack<int> stpool;
	//StackAlloc<int, MemoryPool<int> > stackPool;
	start = clock();
	for (int j = 0; j < REPS; j++) {
		assert(stpool.empty());
		for (int i = 0; i < ELEMS; i++)
			stpool.push(i);
		for (int i = 0; i < ELEMS; i++)
			stpool.pop();
	}
	std::cout << "MemoryPool Allocator Time: ";
	std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";
	
	// 使用内存池
	 StackAlloc<int, MemoryPool<int> > stackPool;
	 start = clock();
	 for (int j = 0; j < REPS; j++) {
	     assert(stackPool.empty());
	     for (int i = 0; i < ELEMS; i++)
	       stackPool.push(i);
	     for (int i = 0; i < ELEMS; i++)
	       stackPool.pop();
	 }
	 std::cout << "MemoryPool Allocator Time: ";
	 std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";
	 new int();
	 // 比较内存池和 std::vector 之间的性能
	 std::vector<int> stackVector;
	 start = clock();
	 for (int j = 0; j < REPS; j++) {
		 assert(stackVector.empty());
		 for (int i = 0; i < ELEMS; i++)
			 stackVector.push_back(i);
		 for (int i = 0; i < ELEMS; i++)
			 stackVector.pop_back();
	 }
	 std::cout << "Vector Time: ";
	 std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";

	 return 0;
}