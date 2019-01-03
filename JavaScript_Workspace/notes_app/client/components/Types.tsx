export interface Note {
    name: string,
    body: string,
    tags: []
}

export interface Folder {
    name: string,
    location: string,
    notes: Note[]
}

export interface Tag {
    name: string,
    color: string
}