#pragma once

#include <iostream>

class IMenuCommand
{
public:
	virtual ~IMenuCommand() = default;

	virtual std::wstring GetDescription() const = 0;
	virtual void Execute() const = 0;
};