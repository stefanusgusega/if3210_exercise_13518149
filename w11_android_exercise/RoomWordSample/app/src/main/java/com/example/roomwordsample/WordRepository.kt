package com.example.roomwordsample

import androidx.annotation.WorkerThread
import kotlinx.coroutines.flow.Flow

// declares the DAO as a private property in this ctor.
// Pass in the DAO instead of the whole db, bcs you only
// need access to the DAO
class WordRepository(private val wordDao: WordDao) {
    // room executes all queries on a separate thread
    // observed Flow will notify the observer when the data
    // has changed.
    val allWords: Flow<List<Word>> = wordDao.getAlphabetizedWords()

    // by default Room runs suspend queries off the main thread,
    // therefore, we dont need to implement anything to ensure
    // we're not doing long running db work off the main thread.
    @Suppress("RedundantSuspendModifier")
    @WorkerThread
    suspend fun insert(word: Word) {
        wordDao.insert(word)
    }
}