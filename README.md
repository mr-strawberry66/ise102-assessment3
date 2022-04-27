# Assessment 3 Todos
Your task is to create a digital card collection:
1. Built around a card type you've chosen yourself. DO NOT use Dog, SkateDeck or any other example I've created for you.
2. Built over modules 9-12, having started from our module 9 cards project (under our team ise102-1106 on repl)
3. With at least the ***core features***
4. With extra features if you're aiming for a Credit (65+) or higher mark
5. Ideally, using the {fmt} library for styling/layout

## Core Features

1. Display a menu or list of commands
2. Allow the user to choose a menu item or command
3. List cards in a table format (rows of data with headings)
4. Display an individual card formatted like a collectible card
5. Add a new card
6. Edit an existing card

### Example menus  

You can have a menu and wait for input. Note: If users choose to Display or Edit a card you'd need to list them and get an id from the user (to choose one).
```
[L] List monsters    
[D] Display monster  
[A] Add new monster  
[E] Edit existing monster 
Enter your choice (E.g. D↩)> 
```

Or maybe a help/command setup:
```
> help 
Type any of these commands (with a card id if required) and hit enter (↩). 
 list            Lists monster cards in table with id numbers 
 display <id>    Display a card with the card id <id>. e.g display 24
 add             Add a new card
 edit <id>       Edit existing card with id <id>
 delete <id>     Delete existing card with id <id>

Example command entries:
 > display 12↩
 > edit 12↩
```
Here's a user adding a new monster, and halfway through typing "Mutant"
```
> add
Enter each field and hit enter. If you don't want to supply a value, 
just hit enter. Required fields have an asterisk.
Name*: Roaring Barnacle
Category*: Mut_
```

## Extended Features
Add features for more marks!

### Potential extra features
- Delete card
- Card rarity/element/foil that changes the border/title colour. Eg. Rare: cyan, Epic: magenta
- Card permanence: loading cards from disk instead of creating them all in code, saving new cards to disk
- Constructor functions for card objects with some arguments having default values
- Roll some of the stats based on a range of valid values. E.g. armour could have a base value of 15 plus a random 0-5.
- Undelete most recently deleted card?
 