using HierarchyApp.ViewModels.AdvancedTools;
using Microsoft.UI.Xaml.Controls;

namespace HierarchyApp.Views.AdvancedTools;

public sealed partial class CompaDSPage : Page
{
    public CompaDSViewModel ViewModel { get; } = new CompaDSViewModel();

    public CompaDSPage()
    {
        InitializeComponent();
    }
}
