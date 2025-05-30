import pygame
import os
from os import system
import random


class MusicPlayer:
    def __init__(self):
        pygame.mixer.init()
        self.folder = r"C:\\Users\\Alex\\Music"
        self.playlists = {
            p: [
                os.path.join(self.folder, p, f)
                for f in os.listdir(os.path.join(self.folder, p))
                if f.endswith(".mp3")
            ]
            for p in os.listdir(self.folder)
            if os.path.isdir(os.path.join(self.folder, p))
        }
        self.current_playlist_name = None  # Track selected playlist name
        self.current_playlist = []
        self.track_order = []
        self.index = 0
        self.shuffle_mode = False
        self.current_track = 0
        self.is_paused = False

    def select_playlist(self, name):
        """Select a playlist by name."""
        if name in self.playlists:
            self.current_playlist_name = name  # Store playlist name
            self.current_playlist = self.playlists[name]
            self.track_order = self.current_playlist[:]
            if self.shuffle_mode:
                random.shuffle(self.track_order)
            self.index = 0
            print(f"Selected playlist: {name}")

    def toggle_shuffle(self):
        """Toggle shuffle mode on or off."""
        self.shuffle_mode = not self.shuffle_mode
        if self.current_playlist:
            self.track_order = self.current_playlist[:]
            if self.shuffle_mode:
                random.shuffle(self.track_order)
        print(f"Shuffle {'enabled' if self.shuffle_mode else 'disabled'}")

    def play(self):
        """Play the current track."""
        if self.track_order:
            pygame.mixer.music.load(self.track_order[self.index])
            pygame.mixer.music.play()
            self.current_track = os.path.basename(self.track_order[self.index])
            self.is_paused = False
            print_menu(self.current_track, self.is_paused)

    def next_track(self):
        """Play the next track in the playlist."""
        if self.track_order:
            self.index = (self.index + 1) % len(self.track_order)
            self.play()

    def previous_track(self):
        """Play the previous track in the playlist."""
        if self.track_order:
            self.index = (self.index - 1) % len(self.track_order)
            self.play()

    def pause(self):
        """Pause the currently playing track."""
        pygame.mixer.music.pause()
        self.is_paused = True
        print_menu(self.current_track, self.is_paused)

    def print_playlists(self):
        """Print available playlists."""
        print("\nAvailable Playlists:")
        if self.playlists:
            for playlist_name in self.playlists.keys():
                print(f"- {playlist_name}")
        else:
            print("No playlists found.")


def print_menu(current_track=None, is_paused=False):
    """Print the current playlist and controls."""
    system("cls")
    print('\n')

    if player.current_playlist_name:
        print(f"Current Playlist: {player.current_playlist_name}\n")
    else:
        print("No playlist selected.\n")

    if player.track_order:
        for track in player.track_order:
            print(os.path.basename(track))
    else:
        print("No playlist selected.")

    print(f"\nShuffle: {'Enabled' if player.shuffle_mode else 'Disabled'}")

    if current_track:
        print(f"Now Playing: {current_track}")
        play_sign = "▶" if is_paused else "||"
        print("\n<<", play_sign, ">>")

# Main loop
player = MusicPlayer()
player.print_playlists()

while True:
    command = input("\nEnter command (select [name], play, next, prev, pause, shuffle, exit): ").strip().lower()

    if command.startswith("select"):
        parts = command.split(maxsplit=1)
        if len(parts) == 2:
            playlist_name = parts[1].strip()
            player.select_playlist(playlist_name)
        else:
            print("Invalid usage. Try: select [playlist_name]")

    elif command == "play":
        player.play()
    elif command == "next":
        player.next_track()
    elif command == "prev":
        player.previous_track()
    elif command == "pause":
        player.pause()
    elif command == "shuffle":
        player.toggle_shuffle()
    elif command == "exit":
        pygame.mixer.music.stop()
        break  # Exit loop

    print_menu(player.current_track, player.is_paused)