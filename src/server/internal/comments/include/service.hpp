#pragma once

class Comment;

class CommentInterface {
    static Comment get(Comment &comment);
    static Comment add(Comment &comment);
    static Comment modify(Comment &comment);
    static Comment remove(Comment &comment);

    static int bump(Comment &comment);
    static int sage(Comment &comment);
};