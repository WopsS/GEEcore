import { DefaultTheme, defineConfig } from "vitepress";

export default defineConfig({
    base: "/GEEcore/",

    lang: "en-US",
    title: "GEEcore",
    description:
        "A library that contains core utilities to create script extenders for different games.",

    lastUpdated: true,
    cleanUrls: true,

    themeConfig: {
        outline: "deep",
        externalLinkIcon: true,

        nav: [
            { text: "Home", link: "/" },
            { text: "Documentation", link: "/introduction/what-is-geecore" }
        ],

        sidebar: sidebar(),

        search: {
            provider: "local"
        },

        socialLinks: [
            { icon: "github", link: "https://github.com/WopsS/GEEcore" }
        ],

        editLink: {
            pattern: "https://github.com/WopsS/GEEcore/edit/master/docs/:path",
            text: "Edit this page on GitHub"
        }
    }
});

function sidebar(): DefaultTheme.SidebarItem[] {
    return [
        {
            text: "Introduction",
            collapsed: false,
            base: "/introduction/",
            items: [
                { text: "What is GEEcore?", link: "what-is-geecore" },
                { text: "Getting Started", link: "getting-started" }
            ]
        },
        {
            text: "Core Concepts",
            collapsed: false,
            base: "/core-concepts/",
            items: [
                { text: "Driver", link: "driver" },
                { text: "Service Container", link: "service-container" }
            ]
        },
        {
            text: "The Basics",
            collapsed: false,
            base: "/basics/",
            items: [
                { text: "Host", link: "host" },
                { text: "MessageBox", link: "messagebox" }
            ]
        },
        {
            text: "Contributors",
            collapsed: false,
            base: "/contributors/",
            items: [
                { text: "Coding Guidelines", link: "coding-guidelines" },
                { text: "Testing Guidelines", link: "testing-guidelines" }
            ]
        }
    ];
}
