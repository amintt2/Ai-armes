import { createClient } from '@supabase/supabase-js';

if (!process.env.NEXT_PUBLIC_SUPABASE_URL) {
  throw new Error('Missing environment variable NEXT_PUBLIC_SUPABASE_URL');
}

if (!process.env.NEXT_PUBLIC_SUPABASE_ANON_KEY) {
  throw new Error('Missing environment variable NEXT_PUBLIC_SUPABASE_ANON_KEY');
}

/**
 * Creates a Supabase client with the provided URL and API key.
 */
export const supabase = createClient(
  process.env.NEXT_PUBLIC_SUPABASE_URL,
  process.env.NEXT_PUBLIC_SUPABASE_ANON_KEY,
  {
    auth: {
      persistSession: true,
      autoRefreshToken: true,
    },
  }
);

/**
 * Types for database tables
 */
export type User = {
  id: string;
  email: string;
  full_name: string | null;
  subscription_tier: string;
  subscription_status: string;
  created_at: string;
  updated_at: string;
};

export type UserPreferences = {
  id: string;
  user_id: string;
  use_cloud: boolean;
  learn_from_input: boolean;
  preferred_mode: string;
  created_at: string;
  updated_at: string;
};

export type AppSettings = {
  id: string;
  user_id: string;
  app_name: string;
  settings: Record<string, unknown>;
  created_at: string;
  updated_at: string;
};

export type ContextData = {
  id: string;
  user_id: string;
  app_name: string;
  context_type: string;
  context: string;
  frequency: number;
  created_at: string;
  updated_at: string;
};

export type Subscription = {
  id: string;
  user_id: string;
  stripe_customer_id: string | null;
  stripe_subscription_id: string | null;
  plan_id: string;
  status: string;
  current_period_start: string;
  current_period_end: string;
  cancel_at_period_end: boolean;
  created_at: string;
  updated_at: string;
};

export type Device = {
  id: string;
  user_id: string;
  device_name: string;
  device_type: string;
  os_type: string;
  last_synced: string;
  created_at: string;
  updated_at: string;
}; 