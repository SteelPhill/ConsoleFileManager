#pragma once

#include <iostream>
#include "IMenuCommand.h"

class IMenu
{
public:
	virtual ~IMenu() = default;

	virtual void AddCommand(IMenuCommand* command) = 0;
	virtual void Start() = 0;
};