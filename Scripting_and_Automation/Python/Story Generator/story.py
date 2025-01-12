import random

character = [
    "The dragon", "The princess", "The knight", "The wizard", "The alien",
    "The warrior", "The sorceress", "The robot", "The giant spider", "The pirate",
    "The wolf", "The mermaid", "The hunter", "The vampire", "The ghost", "The giant", 
    "The witch", "The elf", "The zombie", "The nymph"
]

places = [
    "in the castle", "in the forest", "in space", "in the village", "on the mountain", 
    "at the bottom of the sea", "on a desert island", "in the secret laboratory", 
    "in the futuristic city", "in a mysterious cave", "in the desert", 
    "on the moon", "in an abandoned city", "in the realm of shadows", "in the ancient temple",
    "at the top of a tower", "in a medieval city", "in the swamp", "on a ghost ship"
]

actions = [
    "flew", "fought a monster", "cast a spell", "rescued someone", 
    "invaded a party", "attacked with a sword", "solved a mystery", 
    "sailed through dangerous seas", "found a treasure", "ran to escape a dragon", 
    "died and came back to life", "transformed into an animal", "sacrificed something important", 
    "time traveled", "explored a secret cave", "climbed a giant tree"
]

items = [
    "a magic sword", "an invisible cloak", "an ancient spell", "a treasure map", 
    "a enchanted stone", "a glowing crystal", "a spellbook", "an iron shield", 
    "a enchanted compass", "an elixir of immortality", "a golden key", "a ring of the gods", 
    "an enchanted bracelet", "a dragon's heart", "an angel's wing"
]

emotions = [
    "happy", "furious", "sad", "surprised", "anxious", "desperate", 
    "confused", "proud", "ashamed", "enchanted", "scared", "relieved", 
    "disillusioned", "grateful", "vengeful", "curious", "delirious", "drunk"
]

events = [
    "found an unexpected ally", "discovered a dark secret", 
    "was betrayed by a friend", "won a mysterious prize", 
    "lost something very important", "found a vital clue", 
    "narrowly escaped danger", "had a great confrontation", 
    "made a new enemy", "discovered a magical portal", "turned an enemy into a friend", 
    "found a mythical creature", "was blessed by a deity", 
    "had a vision of the future", "unlocked a hidden power", 
    "found a lost artifact", "was attacked by a horde of enemies"
]

professions = {
    "The dragon": ["flew", "fought a monster", "destroyed a village", "sacrificed something important"],
    "The princess": ["rescued someone", "invaded a party", "danced at a ball", "transformed into an animal"],
    "The knight": ["fought a monster", "rescued someone", "protected the kingdom", "time traveled"],
    "The wizard": ["cast a spell", "fought a monster", "created a potion", "unlocked a hidden power"],
    "The alien": ["invaded a party", "cast a spell", "abducted a cow", "found a vital clue"],
    "The warrior": ["attacked with a sword", "solved a mystery", "fought in a battle", "explored a secret cave"],
    "The sorceress": ["cast a spell", "discovered a secret", "fought a monster", "turned an enemy into a friend"],
    "The robot": ["did a calculation", "explored a laboratory", "saved the city", "had a vision of the future"],
    "The giant spider": ["attacked its prey", "hid in the web", "invaded a house", "found a lost artifact"],
    "The pirate": ["sailed through dangerous seas", "found a treasure", "attacked an enemy ship", "was attacked by a horde of enemies"],
    "The wolf": ["ran through the forest", "hunted prey", "defended its territory", "hid in the shadows"],
    "The mermaid": ["sang a hypnotic song", "rescued a sailor", "lost her voice", "explored the deep sea"],
    "The hunter": ["shot a deer", "captured a rare creature", "hunted monsters", "found a lost artifact"],
    "The vampire": ["bit someone", "cast a hypnosis spell", "was banished to the underworld", "discovered a magical portal"],
    "The ghost": ["scared a person", "made an appearance", "disappeared mysteriously", "found an unexpected ally"],
    "The giant": ["destroyed a city", "attacked a castle", "rescued a friend", "found a dark secret"],
    "The witch": ["cast a spell", "found a magic potion", "brought a dead person back to life", "transformed into an animal"],
    "The elf": ["shot with a bow and arrow", "cast a spell", "explored the kingdom", "healed someone with magic"],
    "The zombie": ["attacked a city", "lost its brain", "reanimated", "chased prey"],
    "The nymph": ["tended a forest", "performed a mystical dance", "protected the balance of nature", "healed a magical tree"]
}

def generate_story():
    chosen_character = random.choice(character)
    action = random.choice(professions[chosen_character])
    place = random.choice(places)
    item = random.choice(items)
    emotion = random.choice(emotions)
    event = random.choice(events)

    story = f"{chosen_character}, {emotion}, {action} {place} with {item}. During the journey, {chosen_character} {event}."
    return story

print(generate_story())
