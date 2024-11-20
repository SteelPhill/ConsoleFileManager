#include "SubmenuExecuterCommand.h"

SubmenuExecuterCommand::SubmenuExecuterCommand(IMenu* submenu, std::wstring description)
{
	this->submenu = submenu;
	this->description = description;
}

std::wstring SubmenuExecuterCommand::GetDescription() const
{
	return description;
}

void SubmenuExecuterCommand::Execute() const
{
	submenu->Start();
}