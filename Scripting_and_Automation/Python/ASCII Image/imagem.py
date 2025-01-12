from PIL import Image

ASCII_CHARS = ["@", "#", "S", "%", "?", "*", "+", ";", ":", ",", "."]

def resize_image(image, new_width=100):
    width, height = image.size
    ratio = height / width
    new_height = int(new_width * ratio)
    resized_image = image.resize((new_width, new_height))
    return resized_image

def grayify(image):
    return image.convert("L")

def pixel_to_ascii(pixel_value):
    pixel_value = max(0, min(pixel_value, 255))
    return ASCII_CHARS[pixel_value // 25]

def image_to_ascii(image_path, new_width=100):
    try:
        image = Image.open(image_path)
    except Exception as e:
        print(f"Error opening image: {e}")
        return None

    image = resize_image(image, new_width)
    image = grayify(image)
    pixels = list(image.getdata())
    ascii_str = ''.join([pixel_to_ascii(pixel) for pixel in pixels])
    ascii_str_len = len(ascii_str)
    ascii_str = '\n'.join([ascii_str[i:i + new_width] for i in range(0, ascii_str_len, new_width)])
    return ascii_str

def save_to_file(ascii_str, output_file):
    with open(output_file, "w") as f:
        f.write(ascii_str)

def main(image_path, output_file="output.txt", new_width=100):
    ascii_art = image_to_ascii(image_path, new_width)
    if ascii_art:  
        print(ascii_art)
        save_to_file(ascii_art, output_file)
    else:
        print("Failed to generate ASCII art.")

if __name__ == '__main__':
    image_path = input("Enter the image path: ").strip()  
    if image_path:  
        main(image_path)
    else:
        print("No image path provided.")
