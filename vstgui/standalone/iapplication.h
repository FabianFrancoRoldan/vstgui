#pragma once

#include "fwd.h"
#include "interface.h"
#include "iwindow.h"
#include <vector>
#include <cstdint>

//------------------------------------------------------------------------
namespace VSTGUI {
namespace Standalone {

//------------------------------------------------------------------------
class IApplication : public Interface
{
public:
	using WindowList = std::vector<WindowPtr>;
	using CommandLineArguments = std::vector<UTF8String>;

	/** Get the global instance of the application*/
	static IApplication& instance ();
	/** Get the application delegate */
	virtual Application::IDelegate& getDelegate () const = 0;
	/** Get the application preferences */
	virtual IPreference& getPreferences () const = 0;
	virtual const CommandLineArguments& getCommandLineArguments () const = 0;

	/** Create a new window
	 *
	 *	@param config window configuration
	 *	@param controller window controller (can be nullptr)
	 */
	virtual WindowPtr createWindow (const WindowConfiguration& config,
	                                const WindowControllerPtr& controller) = 0;
	/** Get all application windows
	 *
	 *	@note The active window will be the first in the list.
	 */
	virtual const WindowList& getWindows () const = 0;
	/** Show an application wide modal alert box
	 *
	 *	@param config alert box configuration
	 */
	virtual AlertResult showAlertBox (const AlertBoxConfig& config) = 0;
	/** Show an alert box modal to a window
	 *
	 *	@param config alert box configuration
	 */
	virtual void showAlertBoxForWindow (const AlertBoxForWindowConfig& config) = 0;
	/** Register a command
	 *
	 *	The command will be added to the application menu. When the menu item is selected the
	 *command
	 *	is first dispatched to the active window and then to the application delegate.
	 *
	 *	@param command command name and group
	 *	@param defaultCommandKey default command key
	 */
	virtual void registerCommand (const Command& command, char16_t defaultCommandKey) = 0;
	/** Quit the application */
	virtual void quit () = 0;
};

//------------------------------------------------------------------------
} // Standalone
} // VSTGUI
