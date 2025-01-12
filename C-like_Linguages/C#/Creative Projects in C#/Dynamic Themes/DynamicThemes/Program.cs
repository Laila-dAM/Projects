using System;
using System.Drawing;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

class theme {
    static async Task Main(string[] args){
        Console.WriteLine("Enter the path to the image:");
        string imagePath = Console.ReadLine();
        Console.WriteLine("Enter your Figma API token:");
        string figmaApiToken = Console.ReadLine();
        Console.WriteLine("Enter the Figma file key:");
        string figmaFileKey = Console.ReadLine();

        try {
            Bitmap image = new Bitmap(imagePath);
            List<Color> dominantColors = GetDominantColors(imagem, 5);
            Dictionary<string, string> theme = GenerateTheme(dominantColors);
            await UploadThemeToFigma(figmaApiToken, figmaFileKey, theme);
            Console.WriteLine("Theme successfully uploaded to Figma.");
        }
catch(Exception ex) {
    Console.WriteLine($"Error:{ex.Message}");
}
}
static List<Color> GetDominantColor(Bitmap image, int colorCount) {
    Dictionary<Color, int> colorFrequency = new Dictionary<Color, int>();
    for(int x = 0; x < image.Width; x++){
        for(int y = 0; y < image.Height; y++){
            Color pixelColor = image.GetPixel(x, y);
            if(colorFrequency.ContainsKey(pixelColor))
                colorFrequency[pixelColor]++;
    else
        colorFrequency[pixelColor] = 1;
        }
    }
    return colorFrequency
        .OrderByDescending(kvp => kvp.Value)
        .Take(colorCount)
        .Select(kvp => kvp.Key)
        .ToList();
}
static Dictionary<string, string> GenerateTheme(List<Color> colors) {
    Dictionary<string, string> theme = new Dictionary<string, string>();

    for(int i = 0; i < color.Count; i++){
        string colorName = $"Color{i + 1}";
        string hexColor = $"#{colors[i].R:X2}{colors[i].G:X2}{colors[i].B:X2}";
        theme[colorName] = hexColor;
    }
    return theme;
}
static asysnc Task UploadThemeToFigma(string apiToken, string fileKey, Dictionary<string, string> theme) {
    using HttpClient client = new HttpClient();
        string url = $"https://api.figma.com/v1/files/{fileKey}";
        client.DefaultRequestHeaders.Add("Authorization", $"Bearer {apiToken}");

    var themeDate = new {
        name = "Dynamic Theme",
            colors = theme
    };
    
}
}