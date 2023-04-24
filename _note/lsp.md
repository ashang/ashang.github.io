---
title: LSP (Language Server Protocol)
tags: ["lsp"]
date: 2012-02-09
author: ast
---

## LSP (Language Server Protocol)

Adding features like auto complete, go to definition, or documentation on hover for a programming language takes significant effort. Traditionally this work had to be repeated for each development tool, as each tool provides different APIs for implementing the same feature.

A Language Server is meant to provide the language-specific smarts and communicate with development tools over a protocol that enables inter-process communication.

The idea behind the Language Server Protocol (LSP) is to standardize the protocol for how such servers and development tools communicate. This way, a single Language Server can be re-used in multiple development tools, which in turn can support multiple languages with minimal effort.



- LSP - protocol for use between source code editors and LSP servers. The goal of the protocol is to allow programming language support to be implemented and distributed independently of any given editor or IDE.

- LSP server - provides programming language-specific features like code completion, syntax highlighting and marking of warnings and errors, as well as refactoring routines.


The protocol defines the format of the messages sent using JSON-RPC between the development tool and the language server. LSIF defines a graph format to store information about programming artifacts.

The latest version of the LSP specification is version 3.17. There is now also a specification for the upcoming language server index format (LSIF).

## DAP (Debug Adapter Protocol)

Protocol used for debugging support

## Treesitter

Tree-sitter can build a syntax tree for a source file and update the syntax tree as the source file is edited. In neovim it's used for syntax highlighting and indentation.



