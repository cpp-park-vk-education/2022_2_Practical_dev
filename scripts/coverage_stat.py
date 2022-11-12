str = input()

percentege = int(str[str.find("%") - 4:len(str) -1])

if percentege < 50:
    print("What a shame! Such low coverage.")
    exit (1)

if percentege < 80:
    print("Not bad coverage, but you definitely could do better.")
    exit (1)

print("That's a fine coverage you've got. I approve it.")
