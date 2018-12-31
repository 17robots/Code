#Outline
##Note
- Name: string
- Body: html object
- Tags: array

##Tag
- Name: string
- color: string

##Folder
- Name: string
- Location: string
- Notes: array

##Views
###Initial View - The Main View For The Project
- 2 Columns
  - [ ] Note List / Tag List
  - [ ] Note Editor
- Button To Show Hidden Menu
  - [ ] When Pressed, slide everything over and show sidebar
- Sidebar
  - [ ] Display All Folder Locations
  - [ ] Switch Folder
    - [ ] Update Note List
  - [ ] Add Folder Button
  - [ ] Delete Selected Folder Button 
  - [ ] Settings Button

###Settings - Make Changes To The Config Of The Program
- [ ] All Listed Settings Pulled From The Settings Options
- [ ] Each Settings Should Have A Type
- [ ] Load Different Presets Based On Type
- [ ] Save Setting Button

###New Note
- [ ] Modal That Asks For Name Of Note
- [ ] Update Current Note List
- [ ] Make Active Note

###New Tag
- [ ] Modal That Asks For The Name Of The Tag And The Color
- [ ] Updates The List Of Tags

###NewFolder
- [ ] Modal That Asks Folder Location
- [ ] Updates Folder List
- [ ] Set As Active Folder

#Design
##App
Main Component that controls the states and flow of information
Controls What Gets Displayed And When
Handles all of the push and get request from the server as well as passing information for the state to the props

##NoteList
Displays the list of current notes in a certain folder
Updates when the folder changes
Has An Add Note Button To Add A Note In That Folder

##Note
Displays the Name Of The Note and some of the body
Can Be clicked to change the active note

##TagList
Displays the list of current tags
Has An Add Tag Button To Create A Note

##Tag
Displays the Name Of The Tag and the color
When clicked shows all notes that have this tag (dropdown list)

##NewNote
Prompts to allow for new note creation
Sends data and cue to create new note back to app

##NewTag
Prompts to allow for new tag creation
Sends data and cue to create new tag back to app

##Sidebar
Shows all folder locations
Button That Shows Add Folder Location

##NewFolder
Modal That Prompts For Location Of The Folder
Sends data and cue to add new location

##Folder
Displays the name of the folder and part of the location
When Clicked Change The Current Folder

#What Needs Done
- [ ] Folders
  - [ ] Add folder Locations
  - [ ] Remove Folder Locations
- [ ] Notes
  - [ ] Load notes from different folder locations
  - [ ] Create Note
  - [ ] Choose Active Note
  - [ ] Edit Note
  - [ ] Save Note
  - [ ] Delete Note
- [ ] Tags
  - [ ] Create Tag
  - [ ] Delete Tag
    - [ ] When Deleted, Remove From All Notes
  - [ ] Add Tag To Note
  - [ ] Remove Tag From Note