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
            { text: "Guide", link: "/guide/what-is-geecore" }
        ],

        sidebar: {
            "/guide/": { base: "/guide/", items: sidebar() }
        },

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
            items: [
                { text: "What is GEEcore?", link: "what-is-geecore" },
                { text: "Getting Started", link: "getting-started" }
            ]
        },
        {
            text: "Contributors",
            collapsed: false,
            base: "/guide/contributors/",
            items: [{ text: "Testing Guidelines", link: "testing-guidelines" }]
        }
    ];
}
