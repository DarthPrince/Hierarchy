using HierarchyApp.Views.AdvancedTools;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;

namespace HierarchyApp;

public sealed partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    private void NavView_SelectionChanged(NavigationView sender, NavigationViewSelectionChangedEventArgs args)
    {
        if (args.SelectedItem is NavigationViewItem { Tag: string tag })
            Navigate(tag);
    }

    private void Navigate(string tag)
    {
        var pageType = tag switch
        {
            "CompaDS" => typeof(CompaDSPage),
            _ => null
        };

        if (pageType is not null && ContentFrame.CurrentSourcePageType != pageType)
            ContentFrame.Navigate(pageType);
    }
}
