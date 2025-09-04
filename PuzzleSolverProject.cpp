#include "pch.h"

using namespace System;


#include "StartForm.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew PuzzleSolver::StartForm());
  return 0;
}