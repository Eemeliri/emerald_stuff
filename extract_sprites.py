#!/usr/bin/env python3
""" Extract sprites from HGSS follower spritesheets. """
import os.path
import subprocess
import sys
from glob import glob
#import PIL.Image
from PIL import Image

import png


SPRITESHEETS = [('gen1.png', 15, 11, 1)]
output_dir = 'sprites'
print("b")
index_to_name = {}
with open('names.txt', 'r') as f:
    for line in f:
        name, index = line.split(' ')[:2]
        name = name.strip()
        index_to_name[int(index)] = name.lower()
name_to_index = {v: k for k, v in index_to_name.items()}
PKMN_GRAPHICS = os.path.join('graphics', 'pokemon')
f"{index_to_name[3]}"
print(index_to_name[3])

def extract_sprites(spritesheet):
    path, width, height, offset = spritesheet
    print("a")
    for y in range(height):
        for x in range(width):
            if x == 3 and y == 0 or x == 10 and y == 1:
                continue
            output_path = os.path.join(output_dir, f'{offset:03d}.png')
            subprocess.run(['convert', '-extract', f'64x128+{x*(64+1)}+{y*(128+1)}', path, output_path], check=True)
            offset += 1


def stack_sprite(name, path):
    joinp = os.path.join
    name = f'{index}.png'
    frames = [joinp(path, 'down', name), joinp(path, 'down', 'frame2', name),
              joinp(path, 'up', name), joinp(path, 'up', 'frame2', name),
              joinp(path, 'left', name), joinp(path, 'left', 'frame2', name)]
    name = f'{index_to_name[index]}.png'
    output = joinp(path, name)
    subprocess.run(['convert'] + frames + ['+append', output], check=True)
    print(f'Stacked {output}')

def stack_shinysprite(name, path):
    joinp = os.path.join
    name = f'{index}.png'
    frames = [joinp(path, 'shiny', 'down', name), joinp(path, 'shiny', 'down', 'frame2', name),
              joinp(path, 'shiny', 'up', name), joinp(path, 'shiny', 'up', 'frame2', name),
              joinp(path, 'shiny', 'left', name), joinp(path, 'shiny', 'left', 'frame2', name)]
    name = f'{index_to_name[index]}_shiny.png'
    output = joinp(path, name)
    subprocess.run(['convert'] + frames + ['+append', output], check=True)
    print(f'Stacked {output}')

def canonicalize_names():
    for path in glob('overworld/**/*.png', recursive=True):
        head, tail = os.path.split(path)
        name, ext = os.path.splitext(tail)
        try:
            num = int(name)
        except ValueError:
            continue
        new_name = f'{num:03d}'
        new_path = os.path.join(head, new_name+ext)
        os.rename(path, new_path)
        print(path, '->', new_path)

def closest_color(c, palette):
    min_d = float('inf')
    best = 0
    r1, g1, b1 = c
    for i, (r2, g2, b2) in enumerate(palette[1:], 1):
        # Color diff from https://stackoverflow.com/questions/1847092/given-an-rgb-value-what-would-be-the-best-way-to-find-the-closest-match-in-the-d
        d = ((r2-r1)*0.30)**2 + ((g2-g1)*0.59)**2 + ((b2-b1)*0.11)**2
        if d < min_d:
            min_d = d
            best = i
    return best

def apply_palette(palette_file, input_file, output_file):  # Apply one file's palette to another
    plt = png.Reader(palette_file)
    plt.read()
    target_palette = tuple(c[:3] for c in plt.palette())
    inp = png.Reader(input_file)
    w, h, rows, _ = inp.read()
    src_palette = tuple(c[:3] for c in inp.palette())
    with open(output_file, 'wb') as f:
        new_rows = []
        for row in rows:
            new_rows.append([closest_color(src_palette[c], target_palette) if c else 0 for c in row])
        w = png.Writer(width=w, height=h, bitdepth=4, palette=target_palette)
        w.write(f, new_rows)

def paletteify(path, output_path=None):
    output_path = output_path or path
    joinp = os.path.join
    _, tail = os.path.split(path)
    species, _ = os.path.splitext(tail)
    print(species)
    front = png.Reader(joinp(PKMN_GRAPHICS, species, 'anim_front.png'))
    #front = png.Reader(path)
    front.read()
    target_palette = tuple(c[:3] for c in front.palette())
    r, g, b = target_palette[0]
    color = f'rgb({r},{g},{b})'
    # Strip alpha color
    subprocess.run(['convert', path, '+dither', '-colors', "16", path], check=True)
    subprocess.run(['convert', path, '-background', color, '-alpha', 'remove', output_path], check=True)


def paletteifyshiny(path, output_path=None):
    output_path = output_path or path
    joinp = os.path.join
    _, tail = os.path.split(path)
    species, _ = os.path.splitext(tail)
    species = species.split("_")
    front = png.Reader(joinp(PKMN_GRAPHICS, species[0], 'back.png'))
    #front = png.Reader(path)
    front.read()
    target_palette = tuple(c[:3] for c in front.palette())
    r, g, b = target_palette[0]
    color = f'rgb({r},{g},{b})'
    # Strip alpha color
    subprocess.run(['convert', path, '+dither', '-colors', "16", path], check=True)
    subprocess.run(['convert', path, '-background', color, '-alpha', 'remove', output_path], check=True)
    
def extractPalette(infile,outfile):
    im=Image.open(infile)
    pal=im.palette.palette
    #cols=Image.getcolors(im)
    #print(f'{im.getcolors()}')
    
    front = png.Reader(infile)
    front.read()
    target_palette = tuple(c[:3] for c in front.palette())
    r, g, b = target_palette[0]
    color = f'{r} {g} {b}\r\n'
    
    if im.palette.rawmode!='RGB':
        raise ValueError("Invalid mode in PNG palette")

    output=open(outfile,'w')
    output.write('JASC-PAL\r\n0100\r\n16\r\n') # header
    for i in range(0,16):
        try:
            r, g, b = target_palette[i]
            color = f'{r} {g} {b}\r\n'
            #output.write(pal[i:i+3]) # convert RGB to RGB0 before writing 
            output.write(color)
            #output.write('\n')
        except IndexError:
            output.write("0 0 0\r\n")
            continue
    output.close()

# Sprites from https://veekun.com/dex/downloads

if __name__ == '__main__':
    args = sys.argv[1:]
    if args:
        paletteify(args[0])
    else:
        print("cool")
        for index in range(1, 493+1):
            #stack_sprite(index, 'overworld')
            #stack_shinysprite(index, 'overworld')
            try:
                species = index_to_name[index]
                #path = os.path.join('overworld', f'{species}.png')
                output_path = os.path.join('graphics', 'object_events', 'pics', 'pokemon', f'{species}.png')
                #paletteify(path, output_path)
                output_pal = os.path.join('graphics', 'pokemon', f'{species}','follow_normal.pal')
                extractPalette(output_path,output_pal)
                
                #path = os.path.join('overworld', f'{species}_shiny.png')
                #output_path = os.path.join('graphics', 'object_events', 'pics', 'pokemon', f'{species}_shiny.png')
                #paletteifyshiny(path)
                #output_pal = os.path.join('graphics', 'pokemon', f'{species}','follow_shiny.pal')
                #extractPalette(path,output_pal)
                
            except Exception as e:
                print(e.__class__.__name__, e, file=sys.stderr)
                continue   
            
        #for path in sorted(glob('overworld/*.png')):

        #    _, tail = os.path.split(path)
        #    name, _ = os.path.splitext(tail)
        #    output_path = os.path.join('graphics/object_events/pics/pokemon', f'{name}.png')
        #    try:
        #        extract_sprites(path, output_path)
        #    except Exception as e:
        #        print(name, e.__class__.__name__, e, file=sys.stderr)
