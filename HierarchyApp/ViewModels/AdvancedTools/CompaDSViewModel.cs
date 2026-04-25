using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Windows.Storage;
using Windows.Storage.Pickers;
using WinRT.Interop;

namespace HierarchyApp.ViewModels.AdvancedTools;

public partial class CompaDSViewModel : ObservableObject
{
    [ObservableProperty]
    [NotifyPropertyChangedFor(nameof(OldFileName))]
    [NotifyPropertyChangedFor(nameof(HasOldFile))]
    [NotifyCanExecuteChangedFor(nameof(CompareCommand))]
    private StorageFile? _oldFile;

    [ObservableProperty]
    [NotifyPropertyChangedFor(nameof(NewFileName))]
    [NotifyPropertyChangedFor(nameof(HasNewFile))]
    [NotifyCanExecuteChangedFor(nameof(CompareCommand))]
    private StorageFile? _newFile;

    [ObservableProperty]
    [NotifyCanExecuteChangedFor(nameof(CompareCommand))]
    private double _deltaValueThreshold = double.NaN;

    [ObservableProperty]
    [NotifyCanExecuteChangedFor(nameof(CompareCommand))]
    private double _deltaPercentThreshold = double.NaN;

    public string OldFileName => OldFile?.Name ?? string.Empty;
    public string NewFileName => NewFile?.Name ?? string.Empty;
    public bool HasOldFile => OldFile is not null;
    public bool HasNewFile => NewFile is not null;

    private bool CanCompare() =>
        OldFile is not null &&
        NewFile is not null &&
        !double.IsNaN(DeltaValueThreshold) && DeltaValueThreshold > 0 &&
        !double.IsNaN(DeltaPercentThreshold) && DeltaPercentThreshold > 0;

    [RelayCommand]
    private async Task PickOldFileAsync()
    {
        var file = await PickFileAsync();
        if (file is not null)
            OldFile = file;
    }

    [RelayCommand]
    private async Task PickNewFileAsync()
    {
        var file = await PickFileAsync();
        if (file is not null)
            NewFile = file;
    }

    [RelayCommand(CanExecute = nameof(CanCompare))]
    private async Task CompareAsync()
    {
        await Task.CompletedTask;
    }

    private static async Task<StorageFile?> PickFileAsync()
    {
        var picker = new FileOpenPicker
        {
            ViewMode = PickerViewMode.List,
            SuggestedStartLocation = PickerLocationId.DocumentsLibrary,
        };
        picker.FileTypeFilter.Add("*");

        var hwnd = WindowNative.GetWindowHandle(App.MainWindow);
        InitializeWithWindow.Initialize(picker, hwnd);

        return await picker.PickSingleFileAsync();
    }
}
