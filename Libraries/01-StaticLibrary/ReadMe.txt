Reference: https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-170



Walkthrough covers these tasks:
	1)Create a static library project

		To create a static library project in Visual Studio
		1)On the menu bar, choose File > New > Project to open the Create a New Project dialog.
		
		2)At the top of the dialog, set Language to C++, set Platform to Windows, and set Project type to Library.
		
		3)From the filtered list of project types, select Windows Desktop Wizard, then choose Next.
		
		4)In the Configure your new project page, enter MathLibrary in the Project name box to specify a name for the project. Enter StaticMath in the Solution name box. Choose the Create button to open the Windows Desktop Project dialog.
		
		5)In the Windows Desktop Project dialog, under Application type, select Static Library (.lib).
		
		6)Under Additional options, uncheck the Precompiled header check box if it's checked. Check the Empty project box.
		
		7)Choose OK to create the project.	



	2)Add a class to the static library
	
		1)To create a header file for a new class, right-click to open the shortcut menu for the MathLibrary project in Solution Explorer, and then choose Add > New Item.

		2)In the Add New Item dialog box, select Visual C++ > Code. In the center pane, select Header File (.h). Specify a name for the header file—for example, MathLibrary.h—and then choose the Add button. A nearly blank header file is displayed.

		3)Add a declaration for a class named Arithmetic to do common mathematical operations such as addition, subtraction, multiplication, and division. The code should resemble:

		4)To create a source file for the new class, open the shortcut menu for the MathLibrary project in Solution Explorer, and then choose Add > New Item.	

		5)In the Add New Item dialog box, in the center pane, select C++ File (.cpp). Specify a name for the source file—for example, MathLibrary.cpp—and then choose the Add button. A blank source file is displayed.

		6)Use this source file to implement the functionality for class Arithmetic. The code should resemble:
	
		7)To build the static library, select Build > Build Solution on the menu bar. The build creates a static library, MathLibrary.lib, that can be used by other programs.


	
	3)Create a C++ console app that references the static library
	
		1)In Solution Explorer, right-click on the top node, Solution 'StaticMath', to open the shortcut menu. Choose Add > New Project to open the Add a New Project dialog.

		2)At the top of the dialog, set the Project type filter to Console.

		3)From the filtered list of project types, choose Console App then choose Next. In the next page, enter MathClient in the Name box to specify a name for the project.

		4)Choose the Create button to create the client project.

		5)After you create a console app, an empty program is created for you. The name for the source file is the same as the name that you chose earlier. In the example, it's named MathClient.cpp.
	
	
	
	4)Use the functionality from the static library in the app
		1)Before you can use the math routines in the static library, you must reference it. Open the shortcut menu for the MathClient project in Solution Explorer, and then choose Add > Reference.

		2)The Add Reference dialog box lists the libraries that you can reference. The Projects tab lists the projects in the current solution and any libraries they reference. Open the Projects tab, select the MathLibrary check box, and then choose the OK button.

		3)To reference the MathLibrary.h header file, you must modify the included directories path. In Solution Explorer, right-click on MathClient to open the shortcut menu. Choose Properties to open the MathClient Property Pages dialog box.

		4)In the MathClient Property Pages dialog box, set the Configuration drop-down to All Configurations. Set the Platform drop-down to All Platforms.

		5)Select the Configuration Properties > C/C++ > General property page. In the Additional Include Directories property, specify the path of the MathLibrary directory, or browse for it.

			To browse for the directory path:

			a)Open the Additional Include Directories property value drop-down list, and then choose Edit.

			b)In the Additional Include Directories dialog box, double-click in the top of the text box. Then choose the ellipsis button (...) at the end of the line.

			c)In the Select Directory dialog box, navigate up a level, and then select the MathLibrary directory. Then choose the Select Folder button to save your selection.

			d)In the Additional Include Directories dialog box, choose the OK button.

			e)In the Property Pages dialog box, choose the OK button to save your changes to the project.

		6)You can now use the Arithmetic class in this app by including the #include "MathLibrary.h" header in your code. Replace the contents of MathClient.cpp with this code:
		
		7)To build the executable, choose Build > Build Solution on the menu bar.
	
	
	
	5)Run the app
		1)Make sure that MathClient is selected as the default project. To select it, right-click to open the shortcut menu for MathClient in Solution Explorer, and then choose Set as StartUp Project.
		
		2)To run the project, on the menu bar, choose Debug > Start Without Debugging. The output should resemble:
	
	

Command Line:
For MathLibrary:
cl.exe /c /EHsc MathLibrary.cpp
lib.exe MathLibrary.obj

For MathClient:
cl.exe /EHsc MathClient.cpp /link ..\MathLibrary\MathLibrary.lib
MathClient.exe 
