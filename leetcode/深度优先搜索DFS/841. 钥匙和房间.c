void VisOneRoomDfs(int** rooms, int roomsSize, int* roomsColSize, int curRoom, int* vis)
{
    int i;
    for (i = 0; i < roomsColSize[curRoom]; i++) {
        if (vis[rooms[curRoom][i]] == 1) {
            continue;
        }
        vis[rooms[curRoom][i]] = 1;
        VisOneRoomDfs(rooms, roomsSize, roomsColSize, rooms[curRoom][i], vis);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize)
{
    int* vis = (int*)calloc(roomsSize, sizeof(int));
    int i, j;
    vis[0] = 1;
    VisOneRoomDfs(rooms, roomsSize, roomsColSize, 0 ,vis);

    for (i = 0; i < roomsSize; i++) {
        if (vis[i] != 1) {
            return false;
        }
    }
    return true;
}
