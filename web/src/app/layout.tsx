import type { Metadata } from "next";
import { Inter } from "next/font/google";
import "./globals.css";
import { SupabaseProvider } from "@/contexts/SupabaseContext";
import MainLayout from "@/components/layouts/MainLayout";

const inter = Inter({ subsets: ["latin"] });

export const metadata: Metadata = {
  title: "AI Autocomplete - Smart text suggestions across all your devices",
  description: "A cross-platform, lightweight AI-powered autocomplete app that suggests text contextually and synchronizes your personal context across devices.",
};

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="en">
      <body className={inter.className}>
        <SupabaseProvider>
          <MainLayout>{children}</MainLayout>
        </SupabaseProvider>
      </body>
    </html>
  );
}
