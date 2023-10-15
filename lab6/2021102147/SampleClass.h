#pragma once
class SampleClass
{
public:
	void (*get_private_method_ptr())();
	void call_private_method();

private:
	static void static_private_method();
	void private_method();
};

