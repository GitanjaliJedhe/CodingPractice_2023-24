Reference: https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170

This walkthrough covers these tasks:
	1)Create a DLL project in Visual Studio.
	
	2)Add exported functions and variables to the DLL.
	
	3)Create a console app project in Visual Studio.
	
	4)Use the functions and variables imported from the DLL in the console app.
	
	5)Run the completed app.


Create the DLL project
	1)To create a DLL project in Visual Studio 2019
		1)On the menu bar, choose File > New > Project to open the Create a New Project dialog box.
		At the top of the dialog, set Language to C++, set Platform to Windows, and set Project type to Library.

		2)From the filtered list of project types, select Dynamic-link Library (DLL), and then choose Next.

		3)In the Configure your new project page, enter MathLibrary in the Project name box to specify a name for the project. Leave the default Location and Solution name values. Set Solution to Create new solution. Uncheck Place solution and project in the same directory if it's checked.

		4)Choose the Create button to create the project.
	

	2)To add a header file to the DLL
		1)To create a header file for your functions, on the menu bar, choose Project > Add New Item.

		2)In the Add New Item dialog box, in the left pane, select Visual C++. In the center pane, select Header File (.h). Specify MathLibrary.h as the name for the header file.
	
		3)Choose the Add button to generate a blank header file, which is displayed in a new editor window.
		
		4)Replace the contents of the header file with this code:
	
	
	3)To add an implementation to the DLL
		1) In Solution Explorer, right-click on the Source Files node and choose Add > New Item. Create a new .cpp file called MathLibrary.cpp, in the same way that you added a new header file in the previous step.

		2)In the editor window, select the tab for MathLibrary.cpp if it's already open. If not, in Solution Explorer, double-click MathLibrary.cpp in the Source Files folder of the MathLibrary project to open it.

		3)In the editor, replace the contents of the MathLibrary.cpp file with the following code:
	

Create a client app that uses the DLL
	1)To create a client app in Visual Studio
		1)On the menu bar, choose File > New > Project to open the Create a new project dialog box.

		2)At the top of the dialog, set Language to C++, set Platform to Windows, and set Project type to Console.

		3)From the filtered list of project types, choose Console App then choose Next.

		4)In the Configure your new project page, enter MathClient in the Project name box to specify a name for the project. 
		Leave the default Location and Solution name values. Set Solution to Create new solution. Uncheck Place solution and project in the same directory if it's checked.
		
		5)Choose the Create button to create the client project.
	
	
	2)To add the DLL header to your include path
		1)Right-click on the MathClient node in Solution Explorer to open the Property Pages dialog.

		2)In the Configuration drop-down box, select All Configurations if it's not already selected.

		3)In the left pane, select Configuration Properties > C/C++ > General.

		4)In the property pane, select the drop-down control next to the Additional Include Directories edit box, and then choose Edit.	
	
		5)Double-click in the top pane of the Additional Include Directories dialog box to enable an edit control. Or, choose the folder icon to create a new entry.

		6)In the edit control, specify the path to the location of the MathLibrary.h header file. You can choose the ellipsis (...) control to browse to the correct folder.
		
		7)After you've entered the path to the header file in the Additional Include Directories dialog box, choose the OK button. In the Property Pages dialog box, choose the OK button to save your changes.


	3)To add the DLL import library to your project
		1)Right-click on the MathClient node in Solution Explorer and choose Properties to open the Property Pages dialog.

		2)In the Configuration drop-down box, select All Configurations if it's not already selected. It ensures that any property changes apply to both Debug and Release builds.

		3)In the left pane, select Configuration Properties > Linker > Input. In the property pane, select the drop-down control next to the Additional Dependencies edit box, and then choose Edit.
		
		4)In the Additional Dependencies dialog, add MathLibrary.lib to the list in the top edit control.

		5)Choose OK to go back to the Property Pages dialog box.
		
		6)In the left pane, select Configuration Properties > Linker > General. In the property pane, select the drop-down control next to the Additional Library Directories edit box, and then choose Edit.
		
		7)Double-click in the top pane of the Additional Library Directories dialog box to enable an edit control. In the edit control, specify the path to the location of the MathLibrary.lib file. 
		
		8)Once you've entered the path to the library file in the Additional Library Directories dialog box, choose the OK button to go back to the Property Pages dialog box. Choose OK to save the property changes.
		
		
	4)To copy the DLL in a post-build event
		1)Right-click on the MathClient node in Solution Explorer and choose Properties to open the Property Pages dialog.

		2)In the Configuration drop-down box, select All Configurations if it isn't already selected.

		3)In the left pane, select Configuration Properties > Build Events > Post-Build Event.

		4)In the property pane, select the edit control in the Command Line field. 
		If you followed the directions to put your client project in a separate solution from the DLL project, then enter this command:
			xcopy /y /d "..\..\MathLibrary\$(IntDir)MathLibrary.dll" "$(OutDir)"
			
		5)Choose the OK button to save your changes to the project properties.
		
		