using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Data;

namespace HierarchyApp.Converters;

public sealed class BoolToVisibilityConverter : IValueConverter
{
    public bool Invert { get; set; } = false;

    public object Convert(object value, Type targetType, object parameter, string language)
    {
        var boolValue = value is true;
        return (boolValue ^ Invert) ? Visibility.Visible : Visibility.Collapsed;
    }

    public object ConvertBack(object value, Type targetType, object parameter, string language)
        => throw new NotImplementedException();
}
