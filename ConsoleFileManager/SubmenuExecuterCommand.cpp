#include "SubmenuExecuterCommand.h"

SubmenuExecuterCommand::SubmenuExecuterCommand(std::wstring description, IMenu* submenu)
{
	this->description = description;
	this->submenu = submenu;
}

std::wstring SubmenuExecuterCommand::GetDescription() const
{
	return description;
}

void SubmenuExecuterCommand::Execute() const
{
	submenu->Start();
}