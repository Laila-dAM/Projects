ᴄᴏᴅᴇ 👾

---

# Dynamic Themes

## What is it?

A C# console application that extracts dominant colors from an image, generates a color theme, and uploads it to a Figma file using Figma's API. It automates theme creation based on any image you provide.

## How to use?

1. Make sure you have the [.NET SDK](https://dotnet.microsoft.com/en-us/download) installed.

2. Open a terminal in the project folder and build the project:

```bash
dotnet build
```

3. Run the application:

```bash
dotnet run
```

4. When prompted, enter:
- The path to the image file you want to analyze
- Your Figma API token (get it from your Figma account settings)
- The Figma file key where you want to upload the generated theme

## Features
- Extracts dominant colors from images using bitmap processing
- Generates hex color codes to form a theme
- Uploads the theme dynamically to a Figma file via Figma API
- Uses asynchronous HTTP calls for API interaction
- Simple CLI interface for easy use

## Folder Structure
```bash
📁 Dynamic Themes/
├── DynamicThemes.csproj         # Project configuration
├── Program.cs                  # Main application logic
├── obj/                        # Build artifacts
└── README.md                   # Project documentation
```

## Demo

📹 [Watch it run](link)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
