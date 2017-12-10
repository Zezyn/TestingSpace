pi = 3.14159
radius = 0.00

def volume(radius):
    cyl_volume = (4/3 * float(pi) * float(radius)**3)
    return cyl_volume

print("Volume of a Sphere ")
print(volume(input("Enter a radius: ")))
