#include <iostream>
#include <dlfcn.h>

typedef int (*operation_int)(int, int);
typedef double (*operation_div)(int, int);

int main() {
	void* handle = dlopen("./libcalculator.so", RTLD_LAZY);
	if (!handle) {
		std::cerr << "Cannot open library: " << dlerror() << std::endl;
		return 1;
	}

	// Load functions
	operation_int add = (operation_int)dlsym(handle, "add");
	operation_int subtract = (operation_int)dlsym(handle, "subtract");
	operation_int multiply = (operation_int)dlsym(handle, "multiply");
	operation_div divide = (operation_div)dlsym(handle, "divide");

	if (!add || !subtract || !multiply || !divide) {
		std::cerr << "Cannot load function: " << dlerror() << std::endl;
		dlclose(handle);
		return 1;
	}

	int a = 10, b = 5;
	std::cout << "Add: " << add(a, b) << std::endl;
	std::cout << "Subtract: " << subtract(a, b) << std::endl;
	std::cout << "Multiply: " << multiply(a, b) << std::endl;
	try {
		std::cout << "Divide: " << divide(a, b) << std::endl;
	} catch (const char* msg) {
		std::cerr << msg << std::endl;
	}

	dlclose(handle);
	
	return 0;
}
