from slow_print import slow_print

def print_help():
    print('''
        +--- controls: ---+
        | go [directions] |
        |    get [item]   |
        |    use [item]   |
        |     [help]      |
        |  [i] to inspect |
        |   [inventory]   |
        +-----------------+
    ''')

inventory = []
current_location = 'garden'

print_help()

locations = {
    'hall': {
        'west': 'garden',
        'south': 'kitchen',
        'east': 'bedroom',
        'items': ['jacket']
    }, 
    'kitchen': {
        'north': 'hall',
        'items': ['water bottle', 'knife']
    },
    'garden': {
        'east': 'hall',
        'south': '???',
        'items': ['flower']
    },
    'bedroom': {
        'west': 'hall',
        'items': ['pillow']
    },
    '???': {
        'north': 'garden',
    }
}

while True:
    inp = input('>')
    inp = (inp.split(' ', 1))

    if inp[0] == 'help':
        print_help()
    if inp[0] == 'inventory':
        slow_print(f'{", ".join(inventory)}')
    if inp[0] == 'i':
        if current_location in locations:
            slow_print(f'You inspect the {current_location}:')
            if 'items' in locations[current_location]:
                location_items = locations[current_location]['items']
                if location_items:
                    slow_print(f'You see a {", a ".join(location_items)}')
                else:
                    slow_print('There is nothing special here.')
        else:
            slow_print('There is nothing special here.')
        valid_directions = [key for key in locations[current_location] if key != 'items']
        if valid_directions:
            slow_print(f'You can go: {", ".join(valid_directions)}')
        else:
            slow_print(f'You can only go {valid_directions[0]}.')

    if inp[0] == 'get' and 'items' in locations[current_location]:
        if inp[1] in locations[current_location]['items']:
            slow_print(f'You got a {inp[1]}!')
            inventory.append(inp[1])
            locations[current_location]['items'].remove(inp[1])
        else:
            slow_print(f'You do not see a {inp[1]} here.')

    if inp[0] == 'go':
        if inp[1] in locations[current_location]:
            current_location = locations[current_location][inp[1]]
            slow_print(f'You are now in the {current_location}.')
        else:
            slow_print(f'You can not go {inp[1]}!')

    if inp[0] == 'craft' and len(inp) > 1:
        if inp[1] == 'potion':
            if current_location == 'kitchen' and 'flower' in inventory and 'water bottle' in inventory:
                slow_print('You brew a potion!')
                inventory.remove('flower')
                inventory.remove('water bottle')
                inventory.append('potion')
            else:
                slow_print('You do not have the necessary ingredients!')
    
    if current_location == 'kitchen' and 'potion' not in inventory:
        if inp[0] == 'i':
            slow_print('You see a potion brewer.')
            slow_print('Maybe you can use it by [craft][potion]?')
            slow_print('It might require some ingredients from your inventory.')
    
    if current_location == '???':
        if 'potion' not in inventory:
            slow_print('It is too risky to enter...')
        elif 'knife' not in inventory:
            slow_print('You might need a weapon...')
        else:
            slow_print('You see a Dragon!!!')
            inp = input('What will you do? ').split(' ', 1)

            if inp[0] == 'use' and len(inp) > 1:
                if inp[1] == 'knife':
                    slow_print('Are you SURE you want to attack? This creature has done nothing to you...')
                    confirm = input('(y/n) > ').strip().lower()

                    if confirm == 'y':
                        slow_print('You killed the creature...')
                        slow_print('He had a family.')
                        slow_print('He was innocent.')
                        slow_print('He had never hurt anyone, and you KILLED him.')
                        slow_print('...')
                        slow_print('You didn\'t even win the game, you just KILLED an innocent creature...')
                        slow_print('GAME OVER!')
                    else:
                        slow_print('You lower your weapon. Perhaps there is another way out...')
                elif inp[1] == 'potion':
                    slow_print('Are you SURE you want to drink this? You do not know what will happen...')
                    confirm = input('(y/n) > ').strip().lower()

                    if confirm == 'y':
                        slow_print('You drink the potion...')
                        slow_print('Your vision blurs...')
                        slow_print('Everything fades to black...')
                        slow_print('GAME OVER!')
                    else:
                        slow_print('You hesitate... Maybe there is another way out...')