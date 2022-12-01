#pragma once
template <class T>
class AList
{
public:
	virtual void Add(T& item) = 0;
	virtual void WriteAllToConsole() const = 0;
};