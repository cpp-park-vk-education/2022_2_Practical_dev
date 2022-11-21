#pragma once

#include "comments/comments.hpp"

class Comment;

class CommentInterface {
    static Comment get(Comment &comment);
    static void add(Comment &comment);
    static void modify(Comment &comment);
    static void remove(Comment &comment);
    
    static void bump(Comment &comment);
    static void sage(Comment &comment);
};